#ifndef LEG_H
#define LEG_H

#include "drivers/servo/servo.hpp"

using namespace servo;

class Leg {
    public:
        Servo *distalServo;
        Servo *midServo;
        Servo *proximalServo;

        Leg(int distalPort, int midPort, int proximalPort, int location);
        ~Leg();
        void enableServos();
        void disableServos();
        void homeJoint(Servo *servo);
        void moveJoint(Servo *servo, int position);
        void incrementJoint(int joint, int increment);
        void moveLegToHome();

    private:
        int location;
        int distalPosition;
        int midPosition;
        int proximalPosition;

         void initServos();
};

#endif