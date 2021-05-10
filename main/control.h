// Fichier pour la gestion du robot
#include "header.h"
#include "pins_arduino.h"
#include <vector>

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
            void approche(int time);
        
        //Handler
            int robot_handler();

    private:
        vector<int> mesure;
        vector<int> old_mesure;
        vector<int> diff;

        vector<int> vect_follow; //3 mesures droite + centre + gauche 

        int dist_follow;
        int c_recherche;

}; 