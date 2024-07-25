#ifndef HEXAPOD_H
#define HEXAPOD_H

#include <map>

#include "leg.hpp"

class Hexapod {
    public:
        Hexapod();
        ~Hexapod();
        void moveAllToHome();
        void moveLeg(int leg, int joint, int value);
        void moveLegForward(int leg);
        void moveLeftSideForward();
        void moveRightSideForward();
        void enableServos();

    private:
        std::map<int, Leg*> legs;
};

#endif