#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include "itrafficlight.h"



class Pedestrian
{
public:

    coords carPos;


public:
    Pedestrian();

    coords getPos(){
        return carPos;
    }

    void setPos(double x, double y){
        this->carPos.x = x;
        this->carPos.y = y;
    }

    bool ableToMove (TrafficLightState state){
        if (state == TrafficLightState::Green) {
            return true;
        }
        else {
            return false;
        }
    };
};

#endif // PEDESTRIAN_H
