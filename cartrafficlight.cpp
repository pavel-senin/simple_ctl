#include <thread>
#include "cartrafficlight.h"

void CarTrafficLight::setId (const uint8_t newId){
    this->tlInfo.id = newId;
};

uint8_t CarTrafficLight::getId () const{
    return this->tlInfo.id;
};

// Смена состояния по команде контроллера
void CarTrafficLight::setState (TrafficLightState newState){
    this->tlInfo.state = newState;
};

TrafficLightState CarTrafficLight::getState () const{
    return this->tlInfo.state;
};

unsigned int CarTrafficLight::getCounter () const{
    return this->tlInfo.queueCounter;
}

TrafficLightInfo CarTrafficLight::askOther (const ITrafficLight& other) const{
    TrafficLightInfo otherTlInfo;
    otherTlInfo.id = other.getId();
    otherTlInfo.state = other.getState();
    otherTlInfo.queueCounter = other.getCounter();
    return otherTlInfo;
};
