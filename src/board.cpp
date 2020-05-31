// #include "core_simulation.h"
// #include "mydevices.h"
#include "maison.h"
#include "box.h"


int main(){
  // creation d'une board
  Board esp8266;

  //Pour une première ouverture, échange avec l'utilisateur
  cout << "Bonjour et bienvenue sur XiaoMel Domo" << '\n';
  Maison Mamaison = Maison();
  cout << "Quel est le nombre de piece?"<<'\n';
	cin >> Mamaison.nbpiece;
  Mamaison.initialisationmaison(Mamaison.nbpiece);
  Mamaison.getnbpiece(); //renvoie le nombre de pièce
  Mamaison.affiche(); //fonction affichage de la liste des pieces


  //sleep(50);
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
