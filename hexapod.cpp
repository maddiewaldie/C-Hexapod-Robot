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

void Hexapod::liftLeg(int leg, int amount) {
    moveLeg(leg, DISTAL, -amount);
    moveLeg(leg, MID, -amount);
}

void Hexapod::placeLeg(int leg) {
    moveLeg(leg, DISTAL, 0);
    moveLeg(leg, MID, 0);
}

void Hexapod::moveLegForward(int leg, int amount) {
    amount = (leg == RIGHT_FRONT || leg == RIGHT_MIDDLE || leg == RIGHT_BACK) ? -amount : amount;
    moveLeg(leg, PROXIMAL, amount);
}

void Hexapod::centerLeg(int leg) {
    moveLeg(leg, PROXIMAL, 0);
}

void Hexapod::moveLegBackward(int leg, int amount) {
    amount = (leg == RIGHT_FRONT || leg == RIGHT_MIDDLE || leg == RIGHT_BACK) ? amount : -amount;
    moveLeg(leg, PROXIMAL, amount);
}

void Hexapod::moveForward() {
    liftLeg(LEFT_FRONT, 25);
    liftLeg(RIGHT_MIDDLE, 25);
    liftLeg(LEFT_BACK, 25);
    sleep_ms(500);
    
    moveLegForward(LEFT_FRONT, 12);
    moveLegForward(RIGHT_MIDDLE, 8);
    moveLegForward(LEFT_BACK, 12);
    moveLegBackward(RIGHT_FRONT, 12);
    moveLegBackward(LEFT_MIDDLE, 5);
    moveLegBackward(RIGHT_BACK, 12);
    sleep_ms(500);

    placeLeg(LEFT_FRONT);
    placeLeg(RIGHT_MIDDLE);
    placeLeg(LEFT_BACK);
    sleep_ms(500);

    liftLeg(RIGHT_FRONT, 25);
    liftLeg(LEFT_MIDDLE, 25);
    liftLeg(RIGHT_BACK, 25);
    sleep_ms(500);

    moveLegForward(RIGHT_FRONT, 12);
    moveLegForward(LEFT_MIDDLE, 8);
    moveLegForward(RIGHT_BACK, 12);
    moveLegBackward(LEFT_FRONT, 12);
    moveLegBackward(RIGHT_MIDDLE, 5);
    moveLegBackward(LEFT_BACK, 12);
    sleep_ms(500);

    placeLeg(RIGHT_FRONT);
    placeLeg(LEFT_MIDDLE);
    placeLeg(RIGHT_BACK);
    sleep_ms(500);
}

void Hexapod::moveBackward() {
    liftLeg(LEFT_FRONT, 25);
    liftLeg(RIGHT_MIDDLE, 25);
    liftLeg(LEFT_BACK, 25);
    sleep_ms(500);

    moveLegForward(RIGHT_FRONT, 12);
    moveLegForward(LEFT_MIDDLE, 8);
    moveLegForward(RIGHT_BACK, 12);
    moveLegBackward(LEFT_FRONT, 12);
    moveLegBackward(RIGHT_MIDDLE, 5);
    moveLegBackward(LEFT_BACK, 12);
    sleep_ms(500);

    placeLeg(LEFT_FRONT);
    placeLeg(RIGHT_MIDDLE);
    placeLeg(LEFT_BACK);
    sleep_ms(500);

    liftLeg(RIGHT_FRONT, 25);
    liftLeg(LEFT_MIDDLE, 25);
    liftLeg(RIGHT_BACK, 25);
    sleep_ms(500);

    moveLegForward(LEFT_FRONT, 12);
    moveLegForward(RIGHT_MIDDLE, 8);
    moveLegForward(LEFT_BACK, 12);
    moveLegBackward(RIGHT_FRONT, 12);
    moveLegBackward(LEFT_MIDDLE, 5);
    moveLegBackward(RIGHT_BACK, 12);
    sleep_ms(500);

    placeLeg(RIGHT_FRONT);
    placeLeg(LEFT_MIDDLE);
    placeLeg(RIGHT_BACK);
    sleep_ms(500);
}