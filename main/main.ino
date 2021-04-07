#include "header.h"
#include "math.h"

#define BAUDRATE      115200
#define pinTempSensor A0
#define R0            100000
#define B             4250               // B value of the thermistor entre 4250 et 4299
#define TEMP          true
int state = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(LED_BUILTIN_AUX,OUTPUT);

  //temp
  Serial.begin(BAUDRATE);

}

void loop() {
  if (!TEMP){
    // put your main code here, to run repeatedly:
    digitalWrite(LED_BUILTIN,1);
    digitalWrite(LED_BUILTIN_AUX,0);
    delay (1000);
    digitalWrite(LED_BUILTIN,0);
    digitalWrite(LED_BUILTIN_AUX,1);
    delay (1000);
  }else{
    state++;
    int a = analogRead(pinTempSensor);
  
    float R = 1023.0/a-1.0;
    R = R0*R;
    
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
  
    Serial.print("T° = ");
    Serial.print(temperature);
    Serial.print("°C");
    Serial.print("\n\r");
    digitalWrite(LED_BUILTIN,state%2);
  
    delay(10000);
  }
}