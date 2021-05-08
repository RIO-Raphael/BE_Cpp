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
  //robot.servo.set_value(10.0);
  //Serial.println(robot.robot_handler());
  robot.servo.set_value(MIN_SERVO_ANGLE);
  delay(2000);
  robot.servo++;
  delay(2000);
  robot.servo.set_value(MAX_SERVO_ANGLE);
  delay(2000);
  robot.servo--;
  robot.servo--;
  delay(2000);
  robot.servo.set_value(SERVO_MIDDLE);
  delay(10000);
}
