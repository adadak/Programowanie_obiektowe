#pragma once
#include <string>
#include "rand.h"


class CSensor {
private:
    float lowLimit;
    float highLimit;
    float Measurement = 0.0f; //default

    void makeMeasurement() {
        Measurement = getRandomNumber(lowLimit, highLimit);
    }
protected:
    //walidacja zakresu
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

    //konkretna klasa sensora podaje swoj overide
    virtual std::string getName() = 0;
    virtual std::string getUnit() = 0;
};

class CTemperatureSensor : public CSensor {
public:
    CTemperatureSensor(float low, float high)
        : CSensor(low, high) { //najpierw konstruktor klasy bazowej
        checkLimits(-50.0f, 60.0f, -20.0f, 40.0f);
    }
    std::string getName() override {
        return "temperature";
    }
    std::string getUnit() override {
        return "stop. Celsjusza";
    }
};

class CHumiditySensor : public CSensor {
public:
    CHumiditySensor(float low, float high)
        : CSensor(low, high) {
        checkLimits(0.0f, 100.0f, 0.0f, 100.0f);
    }
    std::string getName() override {
        return "humidity";
    }
    std::string getUnit() override {
        return "%";
    }
};

class CPressureSensor : public CSensor {
public:
    CPressureSensor(float low, float high)
        : CSensor(low, high) {
        checkLimits(300.0f, 1100.0f, 950.0f, 1050.0f);
    }
    std::string getName() override {
        return "atmospheric pressure";
    }
    std::string getUnit() override {
        return "hPa";
    }
};

class CWindSensor : public CSensor {
public:
    CWindSensor(float low, float high)
        : CSensor(low, high) {
        checkLimits(0.0f, 100.0f, 0.0f, 40.0f);
    }
    std::string getName() override {
        return "wind speed";
    }
    std::string getUnit() override {
        return "m/s";
    }
};

class CInsolationSensor : public CSensor {
public:
    CInsolationSensor(float low, float high)
        : CSensor(low, high) {
        checkLimits(0.0f, 1500.0f, 0.0f, 1000.0f);
    }
    std::string getName() override {
        return "insolation";
    }
    std::string getUnit() override {
        return "W/m^2";
    }
};
