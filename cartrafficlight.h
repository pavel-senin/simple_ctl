#ifndef CARTRAFFICLIGHT_H
#define CARTRAFFICLIGHT_H

#include "itrafficlight.h"

class CarTrafficLight : public ITrafficLight
{
    TrafficLightInfo tlInfo;
public:
    CarTrafficLight(){
        this->tlInfo.id = 0;
        this->tlInfo.queueCounter = 0;
        this->tlInfo.state = TrafficLightState::Red;
    };
    void setId (const uint8_t newId) override final;
    uint8_t getId () const override final;
    void setState (TrafficLightState newState) override final;
    TrafficLightState getState () const override final;
    unsigned int getCounter () const override final;
    void setCounter (int queueSize){
        this->tlInfo.queueCounter = queueSize;
    };
    TrafficLightInfo askOther (const ITrafficLight& other) const override final;

    void initState(TrafficLightInfo initState){
        this->tlInfo.state = initState.state;
        this->tlInfo.id = initState.id;
        this->tlInfo.queueCounter = 0;
    };
};

#endif // CARTRAFFICLIGHT_H
