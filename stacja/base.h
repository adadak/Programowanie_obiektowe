#pragma once
#include <stdexcept>
#include "sensor.h"

class CBase {
public:
    void readSensors() {
        //walidacja dla wszystkich odcyztów:
        if(
            (t_ptr == nullptr) ||
            (h_ptr == nullptr)
        ) {
            if(t_ptr == nullptr) {
                throw std::logic_error("Temperature is nullptr");
            }
            if(h_ptr == nullptr) {
                throw std::logic_error("Humidity is nullptr");
            }
        }
        lastTemperature = t_ptr->Temperature;
        lastHumidity = h_ptr->Humidity;

    }
    void displayMeasurements() {
        std::cout << lastHumidity << '\n';
        std::cout << lastTemperature << '\n';
    }
    void setTemperatureSensor(CTemperatureSensor * t) {
        this -> t_ptr = t;
    }
    void setHumiditySensor(CHumiditySensor * h) {
        this -> h_ptr = h;
    }
private:
    CTemperatureSensor* t_ptr = nullptr;
    CHumiditySensor* h_ptr = nullptr;
    float lastHumidity = 0.0f;
    float lastTemperature = 0.0f;

};
