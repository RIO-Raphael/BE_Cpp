//#define LED_BUILTIN 2
//#define LED_BUILTIN_AUX 16

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
  Mouvement();
  //Destructeur
  //~Capteur();
  //Fonction
  virtual float get_value(void); 
  private :
};

template <class Y> class Actionneur {
  //Constructeur
  Actionneur();

  //Fonction
  virtual Y set_value(void)=0;
  
};
