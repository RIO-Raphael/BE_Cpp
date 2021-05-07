#include "math.h"
#include "control.h"

#define BAUDRATE      115200

int angle;   // variable to hold the angle for the servo motor
float value=0.0;
int value_m=100;
bool up=true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  delay(1000);
  
  //pinMode(D8,OUTPUT);
}

int a=0;
void loop() {
  
}
