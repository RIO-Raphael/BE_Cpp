//SERVO
//Valeurs en °
#define SERVO_AMP           70.0
#define SERVO_MIDDLE        90.0
#define MAX_SERVO_ANGLE     (SERVO_MIDDLE+SERVO_AMP)
#define MIN_SERVO_ANGLE     (SERVO_MIDDLE-SERVO_AMP)
#define SERVO_DIV           9                           //angle de 15,5° par div          
#define SERVO_PAS           (((2*SERVO_AMP)-1)/SERVO_DIV)
#define SERVO_TPS           100

//MOTEURS
#define MOTOR_PAS_DELAY     6       //=1°
#define MOTOR_MIN_ANGLE     SERVO_PAS/2       //en °

//ROBOT
#define TIME_RECHERCHE      5
#define DIST_TARGET         20
#define MAX_RANGE_DETECT    5      //en cm. Seuil pour detecter un mouvemnt dans recherche()
#define MAX_RANGE_MODIF     100      //en cm. Seuil pour suivre une personne
#define MAX_TIME_APPROCHE   1500
#define VITESSE             0.1     //en cm/ms (pour v_ref=1 m/s)

//PINS
#define PIN_ULTRASON        D3
#define PIN_SERVO           D5
#define PIN_PIR_1           D1
#define PIN_PIR_2           A0
#define PIN_PIR_3           D9
#define PIN_MOTEUR_R        D8
#define PIN_MOTEUR_L        D7