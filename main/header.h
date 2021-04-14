//#define LED_BUILTIN 2
//#define LED_BUILTIN_AUX 16
#include "Servo.h"
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

class Moteur : public Actionneur<int>{
  public :
    //Constructeur
    Moteur(int p);
    //Destructeur
    //~Capteur();
    //Fonction
    virtual void set_value(int value); 
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
