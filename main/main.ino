#include "header.h"
#include "math.h"
#include "Servo.h"

#define BAUDRATE      115200
#define PIN_ULTRASON  D3

#define PIN_SERVO    D5
#define PIN_PIR_1     D1
#define PIN_PIR_2     A0
#define PIN_PIR_3     D9

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
    //TEst PIR
    a++;
    Serial.print(" PIR :");
    if (isPeopleDetected()){
      Serial.println("true");
    }else{
      Serial.println("false");
    }
    Serial.println(a);
   
    
  
  //Test trouver qq
  /*if(pir_1.get_value()){
    moteur_r.set_value(0);
    moteur_l.set_value(255);
    delay(500);
  }else if(pir_2.get_value()){
    moteur_r.set_value(255);
    moteur_l.set_value(0);
    delay(500);
  }else if(pir_3.get_value()){
    moteur_r.set_value(0);
    moteur_l.set_value(255);
    delay(1000);
  }*/
    /*robot.avancer();

    delay(1000);
    robot.tourner_r();
    delay(1000);
    robot.arreter();
    */
    //balayage();   //Balayage du servomoteur

  
    //int RangeInCm;
    //digitalWrite(D8,HIGH);
    //Serial.println("The distance to obstacles in front is: ");
 /*
    RangeInCm = ultrason.get_value(); // two measurements should keep an interval
    Serial.print(RangeInCm);//0~400cm
    
    Serial.println(" cm");
    */
    delay(1000);
    

   /* if(up){
      value++;
      if(value>180.0){
        up=false;
      }
    }else{
      value--;
      if(value<0.0){
        up=true;
      }
    }
    // set the servo position
    servomoteur.set_value(value);*/

    
    //value_m-=10;
    
    // wait for the servo to get there
    delay(15);
  
}
