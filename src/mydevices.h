#ifndef MYDEVICES_H
#define MYDEVICES_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include "core_simulation.h"


// exemple de capteur analogique de temperature, ne pas oublier d'heriter de Device
class AnalogSensorTemperature: public Device {
private:
  // fait osciller la valeur du cpateur de 1
  int alea;
  // valeur de temperature mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
  
public:
  //constructeur ne pas oublier d'initialiser la classe mere
  AnalogSensorTemperature(int d,int  t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

// capteur analogique de luminosite (Etape 3)
class AnalogSensorLuminosity: public Device {
private:
  // fait osciller la valeur du cpateur de 1
  int alea;
  // valeur de luminosite mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
public:
  AnalogSensorLuminosity(int d);
  virtual void run();
};

// exemple d'actionneur digital : une led, ne pas oublier d'heriter de Device
class DigitalActuatorLED: public Device {
private:
  // etat de la LED
  int state;
  // temps entre 2 affichage de l etat de la led
  int temps;
  
public:
    // initialisation du temps de rafraichissement
  DigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// exemple d'actionneur digital : une led, ne pas oublier d'heriter de Device
class IntelligentDigitalActuatorLED: public Device {
private:
  // etat de la LED
  int state;
  // temps entre 2 affichage de l etat de la led
  int temps;
  
public:
    // initialisation du temps de rafraichissement
  IntelligentDigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// exemple d'actionneur sur le bus I2C permettant d'echanger des tableaux de caracteres : un ecran, ne pas oublier d'heriter de Device
class I2CActuatorScreen : public Device{
protected:
    // memorise l'affichage de l'ecran
  char buf[I2C_BUFFER_SIZE];
  
public:
  // constructeur
  I2CActuatorScreen ();
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

//classe interraction extérieure avec le simulateur
class ExternalDigitalSensorButton : public Device{
protected:
  // etat bouton
  int stateb;
  // temps entre 2 affichage de l etat du bouton
  int temps;

public :
  // constructeur
  ExternalDigitalSensorButton(int t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();

};

//classe de détéction de présence via infrarouge
class IrSensor : public Device{
protected :
  // etat bouton
  int stateIR;
  // temps entre 2 affichage de l etat du bouton
  int temps;

public :
  // constructeur;
  IrSensor(int t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

//classe simulant le module RTC de façon grossière, donne l'heure, date jour etc
class  RTC : public Device{
protected :
  // etat bouton
  int state;
  // temps entre 2 affichage de l etat du bouton
  int temps;

public :
  // constructeur;
  RTC(int t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  //virtual void run();
  //fonction qui renvoie la date et l'heure quand on lui demande
  int read_current_datetime();
};




#endif
