# Bureau d'étude de Cpp 2020-2021
-----

## Le projet
Ce projet est un petit robot "suiveur". Pour cela nous avons utilisé :
- 1 carte ESP8266
- 3 capteurs de mouvement, PIR
- 1 servo-motor
- 1 capteur à ultrason
- 2 moteurs et leur roue
- 2 relais
- 1 batterie externe
- 1 châssis fait sur mesure en contre-plaqué 5mm

Veuillez vous référer au diagramme de classe pour connaître les interactions entre ces dernières.

## Charger le code sur la carte
Pour charger notre code sur la carte ESP8266 nous avons utilisé l'IDE arduino et Visual Studio Code. Il est possible d'utiliser n'importe quel éditeur de texte. Dans les deux cas, il faut installer le compilateur arduino et le SDK correspondant à notre carte que nous avons pris sur [Github](https://github.com/esp8266/Arduino). Ensuite il faut configurer la carte avec laquelle on travaille et choisir **NodeMCU 1.0 (ESP-12E Module)** dans **Selected Board** et activer les exceptions en choisissant **Enabled** dans **Exceptions**. Il est aussi théoriquement possible d'augmenter l'_Upload Speed_ cependant notre carte ne fonctionnait qu'avec 115200 comme valeur maximale.
Afin d'utiliser le servo-moteur il faut ajouter la **librairie Arduino servo.h** si elle n'est pas présente à la base. 
Le code est prêt à être _uploadé_.

## Faire fonctionner le robot
Une fois le code chargé sur la carte, le robot met 10 secondes à démarrer, ce qui laisse le temps de le poser au sol. Le robot entre alors dans une phase de **recherche** où détecte le mouvement en utilisant les PIR ou en détectant si quelque chose à **avancer** entre deux balayages de la tête (servo-moteur + ultrason). 
Ensuite il tourne, avance et entre dans la phase de **suivi**. Dans cette phase, le robot détecte le mouvement en utilisant les PIR et en détectant si quelque chose à **avancer ou reculer** (des seuils sont mis en place pour prévenir les bugs potentiels) entre deux balayages. La plage de balayage est aussi réduite. 

## Diagramme de classes
![Diagramme de classes](class_diagram.png?raw=true "Diagramme de classes")