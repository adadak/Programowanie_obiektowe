#include <unistd.h>	//Plik nagłówkowy, w kórym jest zadeklarowana użyta poniżej funkcja sleep()

#include "sensor.h"		//Plik nagłówkowy, w którym należy zadeklarować klasy reprezentujące czujniki
#include "base.h"		//Plik nagłówkowy, w kórym należy zadeklarować klasę reprezentującą stację bazową
#include "exception.h"	// Plik nagłówkowy zawierający definicję klasy wyjątku

int main() {
    CTemperatureSensor TemperatureSensor(-35.0, -30.0);	//Utworzenie obiektu reprezentującego czujnik temperatury
    CHumiditySensor HumiditySensor(95.0, 100.0);				//Utworzenie obiektu reprezentującego czujnik wilgotności
    CPressureSensor PressureSensor(950, 1050);				//Utworzenie obiektu reprezentującego czujnik ciśnienia atmosferycznego
    CWindSensor WindSensor(0, 10000);							//Utworzenie obiektu reprezentującego czujnik prędkości wiatru
    CInsolationSensor InsolationSensor(0, 1000);				//Utworzenie obiektu reprezentującego czujnik nasłonecznienia

    CBase Base1(3);	//Utworzenie pierwszego obiektu reprezentującego stację bazową

    try {
        Base1.setSensor(&TemperatureSensor);		//Przekazanie stacji bazowej adresu czujnika temperatury
    } catch (CException& e) {
        cout << "Adding sensors failed with message: " << e.GetMessage() << endl;
    }

    CBase Base2(Base1);										//Utworzenie drugiego obiektu reprezentujacego stacje bazowa jako kopii pierwszego
    //Base2 = Base1;										//Wykorzystanie operatora przypisania
    try {
        Base1.setSensor(&HumiditySensor);			//Przekazanie stacji bazowej adresu czujnika wilgotności
        Base1.setSensor(&PressureSensor);			//Przekazanie stacji bazowej adresu czujnika ciśnienia atmosferycznego
        Base2.setSensor(&WindSensor);				//Przekazanie stacji bazowej adresu czujnika prędkości wiatru
        Base2.setSensor(&InsolationSensor);		//Przekazanie stacji bazowej adresu czujnika nasłonecznienia
    } catch (CException& e) {
        cout << "Adding sensors failed with message: " << e.GetMessage() << endl;
    }

    while(true) {						//Pętla nieskończona (przerwanie programu wymaga użycia klwiszy Ctrl+C)
        cout << "B1" << endl;
        Base1.displayMeasurements();		//Odczyt danych z czujników i wyświetlenie danych w konsoli
        cout << "B2" << endl;
        Base2.displayMeasurements();		//Odczyt danych z czujników i wyświetlenie danych w konsoli
        sleep(3);								//3-sekundowa pauza
    };

    return 0;
}
