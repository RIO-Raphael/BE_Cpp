#include "header.h"
#include "math.h"

#define BAUDRATE      115200
#define PIN_ULTRASON  D3
#define PIN_MOTEUR    D6

Ultrason ultrason(PIN_ULTRASON);
Moteur moteur(PIN_MOTEUR);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
    int RangeInCm;
 
    Serial.println("The distance to obstacles in front is: ");
 
    RangeInCm = ultrason.get_value(); // two measurements should keep an interval
    Serial.print(RangeInCm);//0~400cm
    Serial.println(" cm");
    delay(250);
}
