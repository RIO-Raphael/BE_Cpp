#include "math.h"
#include "control.h"

#define BAUDRATE      115200

Ultrason ultrason(PIN_ULTRASON);
Mouvement pir_1(PIN_PIR_1);
Mouvement pir_2(PIN_PIR_2);
Mouvement pir_3(PIN_PIR_3);
Robot robot;
ServoMoteur servomoteur(PIN_SERVO);

int angle;   // variable to hold the angle for the servo motor
float value=0.0;
int value_m=100;
bool up=true;


//Def de function
void balayage(void){
  for (int i=30;i<150;i++){
    servomoteur.set_value(float(i));
    delay(30);
  }
}
boolean isPeopleDetected() {
    int sensorValue = digitalRead(PIN_PIR_1);
    if(sensorValue == HIGH)//if the sensor value is HIGH?
    {
        return true;//yes,return ture
    }
    else
    {
        return false;//no,return false
    }

    //ANALOG
    /*
    int sensor_read=analogRead(PIN_PIR_2);
    Serial.println(sensor_read);
    if (sensor_read>500){
      return true;
    }else{
      return false;
    }
    */
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  delay(1000);
  pinMode(PIN_PIR_1, INPUT);
  //pinMode(D8,OUTPUT);
}

int a=0;
void loop() {
  
}
