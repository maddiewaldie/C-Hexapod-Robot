#ifndef HEXAPOD_H
#define HEXAPOD_H

#include <map>

#include "leg.hpp"

class Hexapod {
    public:
        Hexapod();
        ~Hexapod();

        void enableServos();
        void moveAllToHome();
        void moveLeg(int leg, int joint, int value);
        
        void liftLeg(int leg, int amount);
        void placeLeg(int leg);
        void moveLegForward(int leg, int amount);
        void centerLeg(int leg);
        void moveLegBackward(int leg, int amount);

        void moveForward();
        void moveBackward();

    private:
        std::map<int, Leg*> legs;
};

#endif