#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include "sensor.h"

class CBase {
public:
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
        Sensors.push_back(pSensor); //dopisuje przekazany adres na koniec wektora push_back to dodanie
    }
private:
    //wektor  trzyma wskaźniki nie kopie czujników
    std::vector<CSensor*> Sensors;
};
