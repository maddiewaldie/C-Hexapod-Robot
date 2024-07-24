#include <algorithm>

#include "constants.h"
#include "leg.hpp"
#include "servoWrapper.hpp"

using namespace servo;

Leg::Leg(int distalPort, int midPort, int proximalPort, int location, bool isSpecial) {
    location = location;
    distalPosition, midPosition, proximalPosition = 0;

    distalServo = new ServoWrapper(distalPort, false, pio0, 0);
    midServo = new ServoWrapper(midPort, isSpecial, pio0, 0);
    proximalServo = new ServoWrapper(proximalPort, isSpecial, pio1, 1);
}

Leg::~Leg() {
    disableServos();

    delete distalServo, midServo, proximalServo;
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

void Leg::homeJoint(ServoWrapper *servo) {
    servo->value(0);
}

void Leg::moveJoint(ServoWrapper *servo, int position) {
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