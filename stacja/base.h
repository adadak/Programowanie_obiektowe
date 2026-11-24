#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include "sensor.h"

#include "exception.h"
#include <cstddef>

class CBase {
public:

    CBase(std::size_t = 5) { //konstruktor klasy inicjalizujacy obiekt CBase
        MaxSensors = limit;
    }
    void displayMeasurements() {
        //pętla po wszytskich elemnatch vector
        for (CSensor* pSensor : Sensors) {

            std::cout << "Current " << pSensor->getName() << ": "   //na obiekcie wskazywanym przez pSensor
                      << pSensor->getMeasurement() << ' ' << pSensor->getUnit() << '\n';
        }
        std::cout << '\n';
    }

    //setter dla wszystkich klas pochodnych CSensor
    void setSensor(CSensor* pSensor) {

        if (pSensor == nullptr) {
            throw std::invalid_argument("Sensor is nullptr");
        }

        if (Sensors.size() >= MaxSensors) {
            throw CException("Maximum number exceeded");
        }

        Sensors.push_back(pSensor); //dopisuje przekazany adres na koniec wektora push_back to dodanie
    }
private:
    //wektor  trzyma wskaźniki nie kopie czujników
    std::vector<CSensor*> Sensors;
    std::size_t MaxSensors; //maksymalna liczba
};
