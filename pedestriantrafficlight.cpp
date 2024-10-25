#include "pedestriantrafficlight.h"

void PedestrianTrafficLight::setId (const uint8_t newId){
    this->tlInfo.id = newId;
};

uint8_t PedestrianTrafficLight::getId () const{
    return this->tlInfo.id;
};

// Пешеходный светофор может в любой момент по запросу из контейнера выполнить
// только два вида переключений: из красного в зеленый и из зеленого в красный
void PedestrianTrafficLight::setState (TrafficLightState newState){
    this->tlInfo.state = newState;
};

TrafficLightState PedestrianTrafficLight::getState () const{
    return this->tlInfo.state;
};

unsigned int PedestrianTrafficLight::getCounter () const{
    return this->tlInfo.queueCounter;
}

TrafficLightInfo PedestrianTrafficLight::askOther (const ITrafficLight& other) const{
    TrafficLightInfo otherTlInfo;
    otherTlInfo.id = other.getId();
    otherTlInfo.state = other.getState();
    otherTlInfo.queueCounter = other.getCounter();
    return otherTlInfo;
};
