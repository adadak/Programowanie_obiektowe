#include <iostream>	//Plik nagłówkowy oraz ...
using namespace std;	//... polecenie użycia nazw z przestrzeni std - niezbędne do poprawnego działania funkcji displayMeasurements()

#include <unistd.h>	//Plik nagłówkowy, w kórym jest zadeklarowana użyta poniżej funkcja sleep()

#include "sensor.h"	//Plik nagłówkowy, w kórym należy zadeklarować klasy reprezentujące czujniki
#include "base.h"		//Plik nagłówkowy, w kórym należy zadeklarować klasę reprezentującą stację bazową

int main() {
    CTemperatureSensor TemperatureSensor(-5.0f, 42.0f);	//Utworzenie obiektu reprezentującego czujnik temperatury
    CHumiditySensor HumiditySensor(-5.0f, 42.0f);			//Utworzenie obiektu reprezentującego czujnik wilgotności
    CPressureSensor PressureSensor(950.0f, 1050.0f);
    CWindSensor WindSensor(0.0f, 40.0f);
    CInsolationSensor InsolationSensor(0.0f, 1100.0f);
    CBase Base;										//Utworzenie obiektu reprezentującego stację bazową

    Base.setSensor(&TemperatureSensor);	//Przekazanie stacji bazowej adresu czujnika temperatury
    Base.setSensor(&HumiditySensor);			//Przekazanie stacji bazowej adresu czujnika wilgotności

    Base.setSensor(&PressureSensor);
    Base.setSensor(&WindSensor);
    Base.setSensor(&InsolationSensor);

    while(true) {						//Pętla nieskończona (przerwanie programu wymaga użycia klwiszy Ctrl+C)
        Base.displayMeasurements();
        sleep(3);										//3-sekundowa pauza
    };

    return 0;
}
