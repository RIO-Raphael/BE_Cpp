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
  if (p==A0){
    digital=false;
  }else{
    digital=true;
  }

  pinMode(p,INPUT);
}

//fonction
bool Mouvement :: get_value(void){
  
  int sensorValue = digitalRead(pin);
  if (digital){
    //DIGITAL
    if(sensorValue == HIGH){
        return true;//yes,return ture
    }else{
      return false;//no,return false
    }
  }else{
    //ANALOG
    int sensor_read=analogRead(pin);
    if (sensor_read>500){
      return true;
    }else{
      return false;
    }
  }

    
}

//################## ACTIONNEURS ##################

//Constructeur
template <class Y> Actionneur <Y>:: Actionneur(int p){
   pin=p;
}

Moteur :: Moteur() : Actionneur(-1){
  
}

Moteur :: Moteur(int p): Actionneur(p){
  pinMode(pin, OUTPUT);
}

//Fonction
void Moteur :: set_value(bool b){

  if(b){
    digitalWrite(pin,HIGH);     
  }else{
    digitalWrite(pin,LOW);  
  }
}
void Moteur :: init_moteur(void){
  pinMode(pin, OUTPUT);
  Serial.println("PIN OK ");
}

void Moteur :: set_pin(int p){
  pin=p;
}

ServoMoteur :: ServoMoteur(int p): Actionneur(p){
  servo.attach(p); // attaches the servo on pin 9 to the servo object
} 

//fonction
void ServoMoteur :: set_value(float value){
  angle=value;
  if(angle>MAX_SERVO_ANGLE){        //Mise en place du saturateur
    angle=MAX_SERVO_ANGLE;
  }
  if(angle<MIN_SERVO_ANGLE){
    angle=MIN_SERVO_ANGLE;
  }
  servo.write(angle);       //Set angle du servo 
}

ServoMoteur ServoMoteur :: operator++(int){
  angle+=SERVO_PAS;
  set_value(angle);
  return *this;
}

ServoMoteur ServoMoteur :: operator--(int){
  angle-=SERVO_PAS;
  set_value(angle);
  return *this;
}