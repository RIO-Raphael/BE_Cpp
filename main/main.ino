#include "control.h"

#define BAUDRATE      115200

Robot robot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  delay(1000);
  
  //pinMode(D8,OUTPUT);
}

int a=0;
void loop() {
  robot.servo.set_value(180.0);
  //Serial.println(robot.robot_handler());
  delay(10000);
}
