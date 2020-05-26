// #include "core_simulation.h"
// #include "mydevices.h"
#include "box.h"


int main(){
  // creation d'une board
  Board esp8266;
  // configue les captures et actionneurs
  Box boxLuminosity(&esp8266,DELAY,1,2,3,4,5,6,2); //configuration de module de lunimosity
  cout << boxLuminosity;
  Box boxTemperature(&esp8266,DELAY,0,7,1);
  cout << boxTemperature;
  Box boxPreJour(&esp8266,DELAY,8,9);
  cout << boxPreJour;

  // allumage de la carte
  esp8266.run();
  return 0;
}