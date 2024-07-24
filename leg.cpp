#include <algorithm>

#include "constants.h"
#include "leg.hpp"
#include "drivers/servo/servo.hpp"

using namespace servo;

Leg::Leg(int distalPort, int midPort, int proximalPort, int location) {
    distalServo = new Servo(distalPort);
    midServo = new Servo(midPort);
    proximalServo = new Servo(proximalPort);

    initServos();
}

Leg::~Leg() {
    disableServos();

    delete distalServo;
    delete midServo;
    delete proximalServo;
}

void Leg::initServos() {
    distalServo->init();
    midServo->init();
    proximalServo->init();
}

void Leg::enableServos() {
    distalServo->enable();
    midServo->enable();
    proximalServo->enable();
}

void Leg::disableServos() {
    distalServo->disable();
    midServo->disable();
    proximalServo->disable();
}

void Leg::homeJoint(Servo *servo) {
    servo->value(0);
}

void Leg::moveJoint(Servo *servo, int position) {
    servo->value(position);
}

void Leg::moveLegToHome() {
    homeJoint(distalServo);
    homeJoint(midServo);
    homeJoint(proximalServo);
}

void Leg::incrementJoint(int joint, int increment) {
    switch(joint) {
        case DISTAL:
            distalPosition = std::max(std::min(distalPosition + increment, 90), -90);
            moveJoint(distalServo, distalPosition);
            break;
        case MID:
            midPosition = std::max(std::min(midPosition + increment, 90), -90);
            moveJoint(midServo, midPosition);
            break;
        case PROXIMAL:
            proximalPosition = std::max(std::min(proximalPosition + increment, 90), -90);
            moveJoint(proximalServo, proximalPosition);
            break;
    }
}