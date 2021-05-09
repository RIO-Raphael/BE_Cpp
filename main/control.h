// Fichier pour la gestion du robot
#include "header.h"
#include "pins_arduino.h"
#include <vector>

#define PIN_ULTRASON    D3
#define PIN_SERVO       D5
#define PIN_PIR_1       D1
#define PIN_PIR_2       A0
#define PIN_PIR_3       D9
#define PIN_MOTEUR_R    D8
#define PIN_MOTEUR_L    D7

#define MAX_RANGE_MODIF 15      //in cm

using namespace std;

class Robot {
    public :
        //Actionneurs
            Moteur moteur_r;
            Moteur moteur_l;
            ServoMoteur servo;
        //Capteurs
            Ultrason ultrason;
            Mouvement pir1;
            Mouvement pir2;
            Mouvement pir3;

        //Constructeur
            Robot();

        //Méthodes
            void avancer();
            void arreter();
            void tourner(int angle);
            float recherche();
            void suivre();
        
        //Handler
            int robot_handler();

    private:
        vector<int> mesure;
        vector<int> old_mesure;
        vector<int> diff;

        int dist_follow;
        int c_recherche;

}; 