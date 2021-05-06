// Class Robot
#include "control.h"

Robot :: Robot(){
  moteur_r.set_pin(PIN_MOTEUR_R);
  moteur_l.set_pin(PIN_MOTEUR_L);
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