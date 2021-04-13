//#define LED_BUILTIN 2
//#define LED_BUILTIN_AUX 16

template <class T> class Capteur {
  
  public :
  //Constructeur
  Capteur();
  //Destructeur
  //~Capteur();
  //Fonction
  virtual T get_value(void)=0; 
  private :
  
};

template <class V> class Ultrason : public class Capteur<V> {
  public :
  //Constructeur
  Ultrason();
  //Destructeur
  //~Capteur();
  //Fonction
  virtual int get_value(); 
  private :
  
};

/*class Mouvement : public class Capteur<float> {
  public :
  //Constructeur
  Mouvement();
  //Destructeur
  //~Capteur();
  //Fonction
  virtual float get_value(void); 
  private :
};*/

template <class Y> class Actionneur {
  //Constructeur
  Actionneur();

  //Fonction
  virtual Y set_value(void)=0;
  
};
