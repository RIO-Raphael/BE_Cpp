#include "control.h"
#include "exception.h"

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
}

int a=0;
void loop() {
  digitalWrite(BUILTIN_LED,HIGH);
  try{
    robot.robot_handler();
  }catch (Robot_Exception e){
    cout << e.Get_message();
    robot.arreter();
    for (int i=0; i<3; i++){
      digitalWrite(BUILTIN_LED,LOW);
      delay(500);
      digitalWrite(BUILTIN_LED,LOW);
      delay(500);
    }
    exit(-1);
  }
 
  //Tempo
  digitalWrite(BUILTIN_LED,LOW);
  delay(10);
}
