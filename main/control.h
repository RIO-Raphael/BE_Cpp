// Fichier pour la gestion du robot
#include "header.h"

class Robot {
  public : 
    Moteur moteur_r;
    Moteur moteur_l;
    //Constructeur
    Robot();
    void avancer();
    void arreter();
    void tourner_r();
    void tourner_l();

}; 