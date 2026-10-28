#pragma once
#include "rand.h"


class CTemperatureSensor {
private:
    float Temperature = 0.0f; //default

    void makeMeasurment(){
    Temperature = getRandomNumber(0.0f, 9.9f);
    }
public:

    float getTemperature(CTemperatureSensor* t){ //przyjmuje wskaźnik do instancji sensora i zwraca pomiar
    makeMeasurment();
     = t_ptr->Temperature;
    }

};

class CHumiditySensor {
public:
    float Humidity = 0.0f;
};
