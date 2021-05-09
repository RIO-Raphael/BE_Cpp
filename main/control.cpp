// Class Robot
#include "control.h"

Robot :: Robot() :
  dist_follow(0),
  c_recherche(INT16_MAX),
  moteur_r(PIN_MOTEUR_R),
  moteur_l(PIN_MOTEUR_L),
  servo(PIN_SERVO),
  ultrason(PIN_ULTRASON),
  pir1(PIN_PIR_1),
  pir2(PIN_PIR_2),
  pir3(PIN_PIR_3)
{
  ultrason.get_value();
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

void Robot :: tourner(int angle){
  if (abs(angle)>MOTOR_MIN_ANGLE){
    if (angle>0){
      moteur_l.set_value(false);
      moteur_r.set_value(true);
    }else{
      moteur_l.set_value(true);
      moteur_r.set_value(false);
    }
    delay (abs(angle*MOTOR_PAS_DELAY));
    arreter();
  }
}

float Robot :: recherche(){
  int ultrason_mes=0;
  int diff=0;
  float angle_detect=-1;
  old_mesure=mesure;
  mesure.clear();

  servo.set_value(MIN_SERVO_ANGLE);
  delay((SERVO_DIV+1)*SERVO_TPS);
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

    delay(SERVO_TPS);
    servo++;
    i++;
    delay(SERVO_TPS);
  }


  if (angle_detect!=-1){
    dist_follow=range;
    servo.set_value(angle_detect);
    old_mesure.clear();
    mesure.clear();
  }

  return angle_detect;
}

void Robot :: approche(){
  //Approche
  c_recherche=0;
  avancer();
  while (dist_follow>DIST_TARGET){
    dist_follow=ultrason.get_value();
    Serial.print("dist_follow=");Serial.println(dist_follow);
    delay(SERVO_TPS);
  } 
  arreter();
}

void Robot :: suivre(){
  int range=0;
  int ok=false;
  for (int i=0; i<3 && !ok; i++){
    servo.set_value(SERVO_MIDDLE-(i-1)*SERVO_AMP);
    delay(SERVO_TPS);
    range=ultrason.get_value();
    if (abs(dist_follow-range)<MAX_RANGE_MODIF && range>DIST_TARGET){
      //On se remet dans l'allignement
      tourner(SERVO_MIDDLE-(i-1)*SERVO_AMP);
      dist_follow=range;
      approche();
    }
    delay(SERVO_TPS);
  }   
  
}

int Robot :: robot_handler(){
  int ultrason_mes=ultrason.get_value();
  float angle_find=-1;
  //recherche
  if (c_recherche>TIME_RECHERCHE){
    while (angle_find==-1){
      angle_find=recherche();
    }
    c_recherche=0;
    tourner(angle_find-SERVO_MIDDLE);
    servo.set_value(SERVO_MIDDLE);
    delay (SERVO_TPS);
    approche();
  }else{
    c_recherche++;
    suivre();
  }
  return (int)angle_find;
}