#include "control.h"

#define BAUDRATE      115200

Robot robot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  delay(1000);
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED,HIGH);
  
  //pinMode(D8,OUTPUT);
}

int a=0;
void loop() {
  //robot.servo.set_value(10.0);
  // int angle=robot.robot_handler();
  // Serial.print("angle=");
  // Serial.println(angle);yt


  // if (angle!=-1){
    
  // }
  //Tempo
  delay(8000);
}
