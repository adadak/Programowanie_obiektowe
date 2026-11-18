#include <unistd.h> //sleep(3)

#include "sensor.h" //klasy reprezentujące czujniki
#include "base.h"   //klasa reprezentująca stację bazową

int main() {
    CTemperatureSensor TemperatureSensor(-5.0f, 42.0f); //Utworzenie obiektu reprezentującego czujnik temperatury
    CHumiditySensor HumiditySensor(-5.0f, 42.0f);       //Utworzenie obiektu reprezentującego czujnik wilgotności
    CPressureSensor PressureSensor(950.0f, 1050.0f);
    CWindSensor WindSensor(0.0f, 40.0f);
    CInsolationSensor InsolationSensor(0.0f, 1100.0f);
    CBase Base; //Utworzenie obiektu reprezentującego stację bazową

    //& pobiera adres obiektu zeby setSensor zapisal w wektorzr CBase
    Base.setSensor(&TemperatureSensor);
    Base.setSensor(&HumiditySensor);
    Base.setSensor(&PressureSensor);
    Base.setSensor(&WindSensor);
    Base.setSensor(&InsolationSensor);

    while(true) { //Pętla nieskończona (przerwanie programu wymaga użycia klwiszy Ctrl+C)
        Base.displayMeasurements(); //odczyt i wyświetlanie wszystkich czujników z wektora
        sleep(3); //3-sekundowa pauza
    };

    return 0;
}
