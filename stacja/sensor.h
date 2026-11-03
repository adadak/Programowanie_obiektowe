#pragma once
#include "rand.h"


class CSensor {
private:

    float lowLimit;
    float highLimit;
protected:
    float Measurement = 0.0f; //default
    void makeMeasurement() {
        Measurement = getRandomNumber(lowLimit, highLimit);
    }
public:
    //konstruktor obiektu sensora
    CSensor(float low, float high) {
        lowLimit = low;
        highLimit = high;
    }


};

class CTemperatureSensor : public CSensor {
public:
    CTemperatureSensor(float low, float high)
        : CSensor(low, high) {
    }

//getter dla temp
    float getTemperature(CTemperatureSensor* t) { //przyjmuje wskaźnik do instancji sensora i zwraca pomiar
        t -> makeMeasurement();
        return t->Measurement;
    }
};
class CHumiditySensor : public CSensor {

public:
    CHumiditySensor(float low, float high)
        : CSensor(low, high) {
    }

//getter dla hum
    float getHumidity(CHumiditySensor* h) {
        h -> makeMeasurement();
        return h->Measurement;
    };

};
