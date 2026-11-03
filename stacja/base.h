#pragma once
#include <stdexcept>
#include "sensor.h"

struct SMeasurement {
    float Temperature;
    float Humidity;
};


class CBase {
public:
    SMeasurement readSensors() {
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

        //zapisz pomaiar w lastX wbijając się do klasy przez wskaźnik
        lastTemperature = t_ptr->getTemperature(t_ptr);
        lastHumidity = h_ptr->getHumidity(h_ptr);


        return SMeasurement{lastTemperature, lastHumidity}; //zwróć jako struct
    }
    void displayMeasurements() {
        std::cout << "Last humidity: " << lastHumidity << '\n';
        std::cout << "Last temperature: " << lastTemperature << '\n';
    }

    void displayMeasurements(const SMeasurement& m) {
        std::cout << "Last humidity: " << m.Humidity << '\n';
        std::cout << "Last temperature: " << m.Temperature << '\n';
    }
    //settery
    void setTemperatureSensor(CTemperatureSensor * t) {
        this -> t_ptr = t; //kopiowanie adresu t do pola t_ptr dla bieżącego obiektu
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
