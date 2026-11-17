#pragma once
#include <string>
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
    void checkLimits(float min, float max, float defaultLow, float defaultHigh) {
        if (!(lowLimit >= min && highLimit <= max && lowLimit < highLimit)) {
            lowLimit = defaultLow;
            highLimit = defaultHigh;
        }
    }
public:
    //konstruktor obiektu sensora
    CSensor(float low, float high) {
        lowLimit = low;
        highLimit = high;
    }
    float getMeasurement() {
        makeMeasurement();
        return Measurement;
    }
    virtual std::string getName() = 0;
    virtual std::string getUnit() = 0;


};

class CTemperatureSensor : public CSensor {
public:
    CTemperatureSensor(float low, float high)
        : CSensor(low, high) {
        checkLimits(-50.0f, 60.0f, -20.0f, 40.0f);
    }
    std::string getName() override { return "temperature"; }
    std::string getUnit() override { return "stop. Celsjusza"; }

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
        checkLimits(0.0f, 100.0f, 0.0f, 100.0f);
    }
    std::string getName() override { return "humidity"; }
    std::string getUnit() override { return "%"; }

//getter dla hum
    float getHumidity(CHumiditySensor* h) {
        h -> makeMeasurement();
        return h->Measurement;
    };

};

class CPressureSensor : public CSensor {
public:
    CPressureSensor(float low, float high)
        : CSensor(low, high) {
        checkLimits(300.0f, 1100.0f, 950.0f, 1050.0f);
    }
    std::string getName() override { return "atmospheric pressure"; }
    std::string getUnit() override { return "hPa"; }
};
class CWindSensor : public CSensor {
public:
    CWindSensor(float low, float high)
        : CSensor(low, high) {
        checkLimits(0.0f, 100.0f, 0.0f, 40.0f);
    }
    std::string getName() override { return "wind speed"; }
    std::string getUnit() override { return "m/s"; }
};
class CInsolationSensor : public CSensor {
public:
    CInsolationSensor(float low, float high)
        : CSensor(low, high) {
        checkLimits(0.0f, 1500.0f, 0.0f, 1000.0f);
    }
    std::string getName() override { return "insolation"; }
    std::string getUnit() override { return "W/m^2"; }
};
