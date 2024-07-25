#ifndef LEG_H
#define LEG_H

#include "servoWrapper.hpp"
#include "drivers/servo/servo.hpp"

using namespace servo;

using namespace servo;

class Leg {
    public:
        Leg() : Leg(0, 0, 0, 0, false) {}
        Leg(int distalPort, int midPort, int proximalPort, int location, bool isSpecial);
        ~Leg();
        void enableServos();
        void disableServos();
        void homeJoint(ServoWrapper *servo);
        void moveJoint(ServoWrapper *servo, int position);
        void incrementJoint(int joint, int increment);
        void moveLegToHome();
        void moveLegForward();

        ServoWrapper *distalServo;
        ServoWrapper *midServo;
        ServoWrapper *proximalServo;

    private:
        int location;
        int distalPosition;
        int midPosition;
        int proximalPosition;
        bool isSpecial;
};

#endif