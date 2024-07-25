#include <map>

#include "constants.h"
#include "hexapod.hpp"

Hexapod::Hexapod() {
    legs = {
        {LEFT_FRONT, new Leg(LEFT_FRONT_DISTAL, LEFT_FRONT_MID, LEFT_FRONT_PROXIMAL, LEFT_FRONT, false)},
        {LEFT_MIDDLE, new Leg(LEFT_MIDDLE_DISTAL, LEFT_MIDDLE_MID, LEFT_MIDDLE_PROXIMAL, LEFT_MIDDLE, false)},
        {LEFT_BACK, new Leg(LEFT_BACK_DISTAL, LEFT_BACK_MID, LEFT_BACK_PROXIMAL, LEFT_BACK, false)},
        {RIGHT_FRONT, new Leg(RIGHT_FRONT_DISTAL, RIGHT_FRONT_MID, RIGHT_FRONT_PROXIMAL, RIGHT_FRONT, false)},
        {RIGHT_MIDDLE, new Leg(RIGHT_MIDDLE_DISTAL, RIGHT_MIDDLE_MID, RIGHT_MIDDLE_PROXIMAL, RIGHT_MIDDLE, false)},
        {RIGHT_BACK, new Leg(RIGHT_BACK_DISTAL, RIGHT_BACK_MID, RIGHT_BACK_PROXIMAL, RIGHT_BACK, true)}
    };
}

Hexapod::~Hexapod() {
    for (auto& legPair : legs) {
        delete legPair.second;
    }
}

void Hexapod::enableServos() {
     for (auto& legPair : legs) {
        legPair.second->enableServos();
    }   
}

void Hexapod::moveAllToHome() {
    for (auto& legPair : legs) {
        legPair.second->moveLegToHome();
    }
}

void Hexapod::moveLeg(int leg, int joint, int value) {
    if (legs.find(leg) != legs.end()) {
        Leg* selectedLeg = legs[leg];
        if (joint == DISTAL) {
            selectedLeg->moveJoint(selectedLeg->distalServo, value);
        } else if (joint == MID) {
            selectedLeg->moveJoint(selectedLeg->midServo, value);
        } else if (joint == PROXIMAL) {
            selectedLeg->moveJoint(selectedLeg->proximalServo, value);
        }
    }
}

void Hexapod::moveLegForward(int leg) {
    moveLeg(leg, DISTAL, -25);
    moveLeg(leg, MID, -25);
    sleep_ms(2000);
    moveLeg(leg, PROXIMAL, 25);
    sleep_ms(2000);
    moveLeg(leg, DISTAL, 0);
    moveLeg(leg, MID, 0);
    sleep_ms(2000);
}

void Hexapod::moveLeftSideForward() {
    moveLegForward(LEFT_FRONT);
    moveLegForward(LEFT_MIDDLE);
    moveLegForward(LEFT_BACK);
}

void Hexapod::moveRightSideForward() {
    moveLegForward(RIGHT_FRONT);
    moveLegForward(RIGHT_MIDDLE);
    moveLegForward(RIGHT_BACK);
}