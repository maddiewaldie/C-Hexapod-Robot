#include <map>

#include "constants.h"
#include "hexapod.hpp"

Hexapod::Hexapod() {
    legs = {
        {LEFT_FRONT, Leg(LEFT_FRONT_DISTAL, LEFT_FRONT_MID, LEFT_FRONT_PROXIMAL, LEFT_FRONT, false)},
        {LEFT_MIDDLE, Leg(LEFT_MIDDLE_DISTAL, LEFT_MIDDLE_MID, LEFT_MIDDLE_PROXIMAL, LEFT_MIDDLE, false)},
        {LEFT_BACK, Leg(LEFT_BACK_DISTAL, LEFT_BACK_MID, LEFT_BACK_PROXIMAL, LEFT_BACK, false)},
        {RIGHT_FRONT, Leg(RIGHT_FRONT_DISTAL, RIGHT_FRONT_MID, RIGHT_FRONT_PROXIMAL, RIGHT_FRONT, false)},
        {RIGHT_MIDDLE, Leg(RIGHT_MIDDLE_DISTAL, RIGHT_MIDDLE_MID, RIGHT_MIDDLE_PROXIMAL, RIGHT_MIDDLE, false)},
        {RIGHT_BACK, Leg(RIGHT_BACK_DISTAL, RIGHT_BACK_MID, RIGHT_BACK_PROXIMAL, RIGHT_BACK, true)}
    };
}

void Hexapod::moveAllToHome() {
    legs[LEFT_FRONT].moveLegToHome();
    legs[LEFT_MIDDLE].moveLegToHome();
    legs[LEFT_BACK].moveLegToHome();
    legs[RIGHT_FRONT].moveLegToHome();
    legs[RIGHT_MIDDLE].moveLegToHome();
    legs[RIGHT_BACK].moveLegToHome();
}

void Hexapod::moveLeg(int leg, int joint, int value) {
    if (joint == DISTAL) {
        legs[leg].moveJoint(legs[leg].distalServo, value);
    } else if (joint == MID) {
        legs[leg].moveJoint(legs[leg].midServo, value);
    } else if (joint == PROXIMAL) {
        legs[leg].moveJoint(legs[leg].proximalServo, value);
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