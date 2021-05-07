#include "Servo.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "pins_arduino.h"

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
    /*
    @brief  : get the distance mesured by the ultrasonic sensor
    @return : range in centimeter
    @param  : none
    */
    virtual int get_value(); 
  
  private :
    int duration();
};

class Mouvement : public Capteur<bool> {
  public :
    //Constructeur
    Mouvement(int p);
    //Méthodes
    /*
    @brief  : get the value of the PIR sensor
    @return : true if someone if detected and false otherwise
    @param  : none
    */
    virtual bool get_value(void); 
  
  private :
    bool digital;
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
    ServoMoteur operator++ (int);
    ServoMoteur operator-- (int);
  private :
    float angle;    //comris entre 0 et 180°
};


