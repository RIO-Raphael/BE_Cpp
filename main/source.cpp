#include "header.h"
#include "Servo.h"
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


Mouvement :: Mouvement(int p):Capteur(p){
  pinMode(p,INPUT);
}

//fonction
float Mouvement :: get_value(void){
  return digitalRead(pin);
}

//################## ACTIONNEURS ##################

//Constructeur
template <class Y> Actionneur <Y>:: Actionneur(int p){
   pin=p;
}

Moteur :: Moteur(int p): Actionneur(p){
  pinMode(pin, OUTPUT);
}

//Fonction
void Moteur :: set_value(int value){
  
  analogWrite(pin,value);     //Value doit être comprise entre 0 et 255 (100% de la PWM)
  /*
  digitalWrite(pin, HIGH);
  delay(100);
  digitalWrite(pin, LOW);
  delay(100);*/

}
void Moteur :: init_moteur(void){
  pinMode(pin, OUTPUT);
  Serial.println("PIN OK ");
}

ServoMoteur :: ServoMoteur(int p): Actionneur(p){
  servo.attach(p); // attaches the servo on pin 9 to the servo object
} 

//fonction
void ServoMoteur :: set_value(float value){
  angle=value;
  if(angle>180.0){        //Mise en place du saturateur
    angle=180.0;
  }
  if(angle<0.0){
    angle=0.0;
  }
  servo.write(angle);       //Set angle du servo 
}
