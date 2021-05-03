//#define LED_BUILTIN 2
//#define LED_BUILTIN_AUX 16

#include "Servo.h"
#include "Arduino.h"

template <class T> class Capteur {
  
  public :
  //Constructeur
  Capteur(int p);
  //Destructeur
  //~Capteur();
  //Fonction
  virtual T get_value(void)=0; 
  protected :
  int pin;
  
};

class Ultrason :  public Capteur<int> {
  public :
  //Constructeur
  Ultrason(int p);
  //Destructeur
  //~Capteur();
  //Fonction
  virtual int get_value(); 
  
  private :
  int duration();
  
};

class Mouvement : public Capteur<float> {
  public :
  //Constructeur
  Mouvement(int p);
  //Destructeur
  //~Capteur();
  //Fonction
  virtual float get_value(void); 
  
  private :
};

template <class Y> class Actionneur {

  public :
    //Constructeur
    Actionneur(int p);

    //Fonction
    virtual void set_value(Y)=0;
    
  protected :
    int pin;
};

class Moteur : public Actionneur<bool>{
  public :
    //Constructeur
    Moteur();
    Moteur(int p);
    //Destructeur
    //~Capteur();
    //Fonction
    virtual void set_value(bool b);
    void set_pin(int p);
    void init_moteur(void);
};

class ServoMoteur : public Actionneur<float> {
  public :
  Servo servo;
  //Constructeur
  ServoMoteur(int p);
  //Destructeur
  //~Capteur();
  //Fonction
  virtual void set_value(float value);
  private :
  float angle;    //comris entre 0 et 180°
};

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
