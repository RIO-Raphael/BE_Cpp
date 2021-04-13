#include "header.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
//Constructeur

template <class T> Capteur <T>:: Capteur(int p){
   pin=p;
}

Ultrason :: Ultrason(int p): Capteur(p){}

int Ultrason :: get_value(){
    int RangeInCentimeters;
    RangeInCentimeters = duration() / 29 / 2;
    return RangeInCentimeters;
}


int Ultrason ::duration() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT);
    int duration;
    duration = pulseIn(pin, HIGH);
    return duration;
}
