#ifndef SERVO_WRAPPER_H
#define SERVO_WRAPPER_H

#include "drivers/servo/servo.hpp"
#include "drivers/servo/servo_cluster.hpp"

using namespace servo;

class ServoWrapper {
    public:
        ServoWrapper(int servoPort, int isCluster, PIO clusterPIO, uint clusterSM);
        ~ServoWrapper();
        void enable();
        void disable();
        void value(int value);
        void toMin();
        void toMid();
        void toMax();
        
    private:
        int isCluster;
        int servoPort;
        uint clusterSM;
        PIO clusterPIO;

        Servo *servo;
        ServoCluster *cluster;

        void init();
};

#endif