//SERVO
#define SERVO_AMP       65.0
#define SERVO_MIDDLE    73.0
#define MAX_SERVO_ANGLE (SERVO_MIDDLE+SERVO_AMP)
#define MIN_SERVO_ANGLE (SERVO_MIDDLE-SERVO_AMP)
#define SERVO_DIV       6   
#define SERVO_PAS       (((2*SERVO_AMP)-1)/SERVO_DIV)
#define SERVO_TPS       50

//MOTEURS
#define MOTOR_PAS_DELAY 7 //=1°
#define MOTOR_MIN_ANGLE 7 //en °

//ROBOT
#define TIME_RECHERCHE  1000
#define DIST_TARGET     30
#define MAX_RANGE_MODIF 20      //in cm

//PINS
#define PIN_ULTRASON    D3
#define PIN_SERVO       D5
#define PIN_PIR_1       D1
#define PIN_PIR_2       A0
#define PIN_PIR_3       D9
#define PIN_MOTEUR_R    D8
#define PIN_MOTEUR_L    D7