#ifndef MYDEVICES_H
#define MYDEVICES_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <ctime>
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

// class AnalogSensor
class AnalogSensor: public Device{
protected:
  // valeur mesure au l'initial
  int val;
  // temps entre 2 prises de valeurs
  int temps;
public:
  AnalogSensor(int d);
  virtual void run();
};

// class DigitalSensor
class DigitalSensor: public Device{
protected:
  int temps;
public:
  DigitalSensor(int d);
  virtual void run();
};

// class AnalogActuator
class AnalogActuator: public Device{
protected:
  // valeur write a pin
  int input;
  int temps;
public:
  AnalogActuator(int t);
  virtual void run();
};

// class DigitalActuator
class DigitalActuator: public Device{
protected:
  // valeur write a pin
  int state;
  int temps;
public:
  DigitalActuator(int d);
  virtual void run();
};

// capteur analogique de temperature
class AnalogSensorTemperature: public AnalogSensor {  
public:
  // constructeur
  AnalogSensorTemperature(int d);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

// capteur analogique de luminosite (Etape 3 du sujet)
class AnalogSensorLuminosity: public AnalogSensor {
public:
  AnalogSensorLuminosity(int d);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// capteur analogique de position de rideau 0 (ferme tout) - 100 (ouvert tout)
class AnalogSensorPosition: public AnalogSensor {
public:
  AnalogSensorPosition(int d);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};


// actionneur digital : une led
class DigitalActuatorLED: public DigitalActuator {
public:
  // initialisation du temps de rafraichiisement
  DigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// actionneur digital : une intellignet led (Etape 4 du sujet)
class IntelligentDigitalActuatorLED: public DigitalActuator {  
public:
  // initialisation du temps de rafraichiisement
  IntelligentDigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// actionneur analog : un moteur de type stepper
class AnalogActuatorMotor: public AnalogActuator{
public:
  // initialisation du temps de rafraichiisement;
  AnalogActuatorMotor(int t);
  // verifie la valeur de position est parmi 0-100
  virtual void checkRange(int in);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

// actionneur analog : une lampe avec 4 niveaux de l'intensite (50lux,100lux,150lux,200lux)
class IntelligentAnalogActuatorLamp: public AnalogActuator{
public:
  // initialisation du temps de rafraichiisement;
  IntelligentAnalogActuatorLamp(int t);
  // verifie le niveau est parmi 0-4
  virtual void checkLevel(int l);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();  
};

// actionneur analog : un moteur de type stepper
class AnalogActuatorChauffClim: public AnalogActuator{
public:
  // initialisation du temps de rafraichiisement;
  AnalogActuatorChauffClim(int t);
  // verifie la valeur de position est parmi 10-25
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
class ExternalDigitalSensorButton : public DigitalSensor{
protected:
  // etat bouton
  int stateb;
public :
  // constructeur
  ExternalDigitalSensorButton(int t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

//classe de détéction de présence via infrarouge
class DigitalSensorIR : public DigitalSensor{
protected :
  // etat
  int stateIR;
public :
  // constructeur;
  DigitalSensorIR(int t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

//classe simulant le module RTC de façon grossière, donne l'heure, date jour etc
class DigitalSensorRTC : public DigitalSensor{
protected :
  // etat du jour : journee = 1, nuit = 0
  int jour;

public :
  // constructeur;
  DigitalSensorRTC(int t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  //virtual void run();
  //fonction qui renvoie la date et l'heure quand on lui demande
  virtual void run();
};



#endif
