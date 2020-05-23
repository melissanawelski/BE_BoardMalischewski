#ifndef MYDEVICES_H
#define MYDEVICES_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "core_simulation.h"

// exception de lampe
class LampException: public exception{
private:
  int lel;
public:
  LampException(int l);
  int getLevel();
};

// exception de range de input valeur
class InputException: public exception{
};

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
  // constructeur ne pas oublier d'initialiser la classe mere
  AnalogSensorTemperature(int d,int  t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

// capteur analogique de luminosite (Etape 3)
class AnalogSensorLuminosity: public Device {
private:
  // valeur de luminosite mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
public:
  AnalogSensorLuminosity(int d);
  virtual void run();
};

// capteur analogique de position de rideau 0 (ferme tout) - 100 (ouvert tout)
class AnalogSensorPosition: public Device {
private:
  // valeur de position mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
public:
  AnalogSensorPosition(int d);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
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
  // initialisation du temps de rafraichiisement
  DigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// actionneur digital : une intellignet led, ne pas oublier d'heriter de Device (Etape 4)
class IntelligentDigitalActuatorLED: public Device {
private:
  // etat de la LED
  int state;
  // temps entre 2 affichage de l etat de la led
  int temps;
  
public:
  // initialisation du temps de rafraichiisement
  IntelligentDigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// actionneur analog : un moteur de type stepper
class AnalogActuatorMotor: public Device{
private:
  // input valeur de moteur
  int input;
  // temps entre 2 affichage de l etat du moteur
  int temps;

public:
  // initialisation du temps de rafraichiisement;
  AnalogActuatorMotor(int t);
  // verifie la valeur de position est parmi 0-100
  virtual void checkRange(int in);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// actionneur analog : une lampe avec 4 niveaux de l'intensite (50lux,100lux,150lux,200lux)
class IntelligentAnalogActuatorLamp: public Device{
private:
  // input niveau de intensite de la lampe
  int level;
  // temps entre 2 affichage de l etat du moteur
  int temps;

public:
  // initialisation du temps de rafraichiisement;
  IntelligentAnalogActuatorLamp(int t);
  // verifie le niveau est parmi 0-4
  virtual void checkLevel(int l);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();  
};

// actionneur analog : un moteur de type stepper
class AnalogActuatorChauffClim: public Device{
private:
  // input valeur de moteur
  int input;
  // temps entre 2 affichage de l etat du moteur
  int temps;

public:
  // initialisation du temps de rafraichiisement;
  AnalogActuatorChauffClim(int t);
  // verifie la valeur de position est parmi 0-100
  virtual void checkFigure(int in);
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

// classe interraction extérieure avec le simulateur
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


#endif
