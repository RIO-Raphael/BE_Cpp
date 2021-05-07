// Class Robot
#include "control.h"

Robot :: Robot() :
    moteur_r(PIN_MOTEUR_R),
    moteur_l(PIN_MOTEUR_L),
    servo(PIN_SERVO),
    ultrason(PIN_ULTRASON),
    pir1(PIN_PIR_1),
    pir2(PIN_PIR_2),
    pir3(PIN_PIR_3)
{
  moteur_r.init_moteur();
  moteur_l.init_moteur();
  //Test valeurs max
  servo.set_value(180.0);
  delay(100);
  servo.set_value(0.0);
  delay(100);
  servo.set_value(90.0);
}

void Robot :: avancer(){
  moteur_r.set_value(true);
  moteur_l.set_value(true);
}
  
void Robot :: arreter(){
  moteur_r.set_value(false);
  moteur_l.set_value(false);
}

void Robot :: tourner_r(){
  moteur_r.set_value(false);
  moteur_l.set_value(true);
}

void Robot :: tourner_l(){
  moteur_r.set_value(true);
  moteur_l.set_value(false); 
}

void Robot :: recherche(){
  int ultrason_mes=ultrason.get_value();
  servo++;
}

int Robot :: robot_handler(){
  int ultrason_mes=ultrason.get_value();



}