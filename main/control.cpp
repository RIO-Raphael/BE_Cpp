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

float Robot :: recherche(){
  int ultrason_mes=ultrason.get_value();
  int diff=0;
  float angle_detect=-1;
  old_mesure.clear();
  mesure.clear();

  servo.set_value(MIN_SERVO_ANGLE);
  while (servo.get_value()<MAX_SERVO_ANGLE){
    servo++;
    old_mesure.push_back(ultrason.get_value());
  }

  servo.set_value(MIN_SERVO_ANGLE);
  while (servo.get_value()<MAX_SERVO_ANGLE){
    servo++;
    mesure.push_back(ultrason.get_value());
  }

  for (int i=0; (i<mesure.size()) && (angle_detect=-1);i++){
    diff=abs(mesure[i]-old_mesure[i]);
    if (diff>MAX_RANGE_MODIF){
      angle_detect=i*SERVO_PAS;
    }
  }

  return angle_detect;
}

int Robot :: robot_handler(){
  int ultrason_mes=ultrason.get_value();
  float angle_find=-1;
  while (angle_find==-1){
    angle_find=recherche();
  }
  return (int)angle_find;
}