#include "header.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

template class Capteur <int>;
template class Capteur <float>;
template class Actionneur <int>;
template class Actionneur <float>;

//Constructeur
template <class T> Capteur <T>:: Capteur(int p){
   pin=p;
}

Ultrason :: Ultrason(int p): Capteur(p){}

//fonction

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

//Constructeur
template <class Y> Actionneur <Y>:: Actionneur(int p){
   pin=p;
}

//################## ACTIONNEURS ##################
Actionneur_PWM :: Actionneur_PWM(int p):Actionneur(p),freq(-1),duty_cycle(0){}
Actionneur_PWM :: Actionneur_PWM(int p, int f):Actionneur(p),freq(f),duty_cycle(0){}

Moteur :: Moteur(int p): Actionneur_PWM(p){} 
Moteur :: Moteur(int p, int f): Actionneur_PWM(p, f){}

//Fonction
void Moteur :: set_value(float value){
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(100);
  digitalWrite(pin, LOW);
  delay(100);

}
