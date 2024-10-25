#ifndef CAR_H
#define CAR_H

#include <cmath>
#include "itrafficlight.h"

class Car
{
    coords carPos;


public:
    Car();

    coords getPos(){
        return carPos;
    }

    void setPos(double x, double y){
        this->carPos.x = x;
        this->carPos.y = y;
    }

    bool ableToMove (Car& other){
        if (std::sqrt(std::pow(this->carPos.x - other.getPos().x,2) +
                      std::pow(this->carPos.y - other.getPos().y,2)) > 50) {
            return true;
        }
        else {
            return false;
        }
    };

};

#endif // CAR_H
