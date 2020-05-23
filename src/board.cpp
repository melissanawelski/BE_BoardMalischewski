// #include "core_simulation.h"
// #include "mydevices.h"
#include "box.h"


int main(){
  // creation d'une board
  Board esp8266;
  
  // Box boxluminosity(&esp8266,DELAY,2,3,5,6,2); //bloc de lunimosity 400
  // cout << boxluminosity;

  ExternalDigitalSensorButton button(DELAY);




  // achat des senseurs et actionneurs
  //AnalogSensorTemperature temperature(DELAY,TEMP);
  DigitalActuatorLED led1(DELAY);
  //I2CActuatorScreen screen1;
  //I2CActuatorScreen screen2;
 

  // senseurs ajouts
  //AnalogSensorLuminosity luminosity(DELAY);
  //AnalogSensorPosition position(DELAY);
  //IntelligentDigitalActuatorLED ledIntel(DELAY);
  //AnalogActuatorMotor moteur(DELAY);
  //IntelligentAnalogActuatorLamp lamp(DELAY);
  //AnalogActuatorChauffClim chauffclim(DELAY);

  
  // branchement des capteurs actionneurs
  //esp8266.pin(1,temperature);
  esp8266.pin(0,led1);
  //esp8266.pin(2,luminosity);
  //esp8266.pin(3,position);
  //esp8266.i2c(1,screen1);
  //esp8266.i2c(2,screen2);
  //esp8266.pin(5,moteur);
  //esp8266.pin(6,lamp);
  //esp8266.pin(7,chauffclim);
  esp8266.pin(4,button);
 
  
  // allumage de la carte
  esp8266.run();
  return 0;
}


