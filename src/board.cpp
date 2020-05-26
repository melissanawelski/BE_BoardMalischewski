// #include "core_simulation.h"
// #include "mydevices.h"
#include "box.h"


int main(){
  // creation d'une board
  Board esp8266;
  // configue les captures et actionneurs
  Box boxluminosity(&esp8266,DELAY,0,1,2,3,4,5,6,1,2); //bloc de lunimosity 400
  //cout << boxluminosity;
  AnalogActuatorChauffClim chauffclim(DELAY);
  esp8266.pin(7,chauffclim);
  DigitalSensorIR ir(DELAY);
  esp8266.pin(8,ir);
  DigitalSensorRTC rtc(DELAY);
  esp8266.pin(9,rtc);






  // allumage de la carte
  esp8266.run();
  return 0;
}