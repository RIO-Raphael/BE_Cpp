#include "control.h"

#define BAUDRATE      115200

Robot robot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  delay(1000);
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED,HIGH);
  
  //Tempo
  delay(5000);
  digitalWrite(BUILTIN_LED,LOW);
  delay(5000);
  digitalWrite(BUILTIN_LED,HIGH);
  //pinMode(D8,OUTPUT);
}

int a=0;
void loop() {
  digitalWrite(BUILTIN_LED,HIGH);
  robot.robot_handler();
  //Tempo
  digitalWrite(BUILTIN_LED,LOW);
  delay(10);
}
