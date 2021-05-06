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

int Robot :: robot_handler(){

}