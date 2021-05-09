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
  servo.set_value(SERVO_MIDDLE);
  delay(1000);
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
  int tps=50;
  int ultrason_mes=ultrason.get_value();
  int diff=0;
  float angle_detect=-1;
  old_mesure=mesure;
  mesure.clear();

  servo.set_value(MIN_SERVO_ANGLE);
  delay(tps);
  int i=0;
  int range=0;
  while (servo.get_value()<MAX_SERVO_ANGLE && angle_detect==-1){
    range=ultrason.get_value();
    mesure.push_back(range);
    if (old_mesure.size()!=0){
      //Debug :
      Serial.print("mesure="); Serial.print(mesure[i]); Serial.print(" et old="); Serial.println(old_mesure[i]);
      diff=abs(mesure[i]-old_mesure[i]);
      if (diff>MAX_RANGE_MODIF){
        angle_detect=MIN_SERVO_ANGLE+i*SERVO_PAS;
      }
    }

    Serial.print("range="); Serial.println(range);

    delay(tps);
    servo++;
    i++;
    delay(tps);
  }


  if (angle_detect!=-1){
    servo.set_value(angle_detect);
    old_mesure.clear();
    mesure.clear();
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