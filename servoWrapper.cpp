#include "servoWrapper.hpp"

ServoWrapper::ServoWrapper(int servoPort, int isCluster, PIO clusterPIO, uint clusterSM) {
    isCluster = isCluster;
    if (isCluster) {
        cluster = new ServoCluster(clusterPIO, clusterSM, servoPort, 1);
    } else {
        servo = new Servo(servoPort);
    }
    init();
}

ServoWrapper::~ServoWrapper() {
    disable();
    isCluster ? delete cluster : delete servo;
}

void ServoWrapper::init() {
    isCluster ? cluster->init() : servo->init();
}

void ServoWrapper::enable() {
    isCluster ? cluster->enable(servoPort) : servo->enable();
}

void ServoWrapper::disable() {
    isCluster ? cluster->disable(servoPort) : servo->disable();
}

void ServoWrapper::value(int value) {
    isCluster ? cluster->value(servoPort, value) : servo->value(value);
}

void ServoWrapper::toMin() {
    isCluster ? cluster->to_min(servoPort) : servo->to_min();
}

void ServoWrapper::toMid() {
    isCluster ? cluster->to_mid(servoPort) : servo->to_mid();
}

void ServoWrapper::toMax() {
    isCluster ? cluster->to_max(servoPort) : servo->to_max();
}