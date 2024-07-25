#include "servoWrapper.hpp"

ServoWrapper::ServoWrapper(int servoPort, int isCluster, PIO clusterPIO, uint clusterSM)
    : isCluster(isCluster), servoPort(servoPort), 
      cluster(isCluster ? new ServoCluster(clusterPIO, clusterSM, servoPort, 1) : nullptr), 
      servo(isCluster ? nullptr : new Servo(servoPort)) {
    init();
}

ServoWrapper::~ServoWrapper() {
    disable();
    delete cluster, servo;
}

void ServoWrapper::init() {
    isCluster ? cluster->init() : servo->init();
}

void ServoWrapper::enable() {
    isCluster ? cluster->enable_all() : servo->enable();
}

void ServoWrapper::disable() {
    isCluster ? cluster->disable_all() : servo->disable();
}

void ServoWrapper::value(int value) {
    isCluster ? cluster->all_to_value(value) : servo->value(value);
}

void ServoWrapper::toMin() {
    isCluster ? cluster->all_to_min(servoPort) : servo->to_min();
}

void ServoWrapper::toMid() {
    isCluster ? cluster->all_to_mid(servoPort) : servo->to_mid();
}

void ServoWrapper::toMax() {
    isCluster ? cluster->all_to_max(servoPort) : servo->to_max();
}