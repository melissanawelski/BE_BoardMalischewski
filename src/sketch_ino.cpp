#include <unistd.h>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
  // on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(2,INPUT); // pin sensor lunimosity
  pinMode(3,OUTPUT); // pin intelligent led
}

// la boucle de controle arduino
void Board::loop(){
  // allume la IntellignetLED
  digitalWrite(3,HIGH);
  // lecture sur la pin 2 : capteur de luminosity
  char bufLum[100];
  int valLum;
  static int cpt=0;
  for(int i=0;i<10;i++){
    valLum=analogRead(2);
    sprintf(bufLum,"luminosity %d",valLum);
    Serial.println(bufLum);
    if(cpt%5==1){
        // tous les 5 fois on affiche sur l ecran la luminosity
      sprintf(bufLum,"%d",valLum);
      bus.write(2,bufLum,100);
    }
    cpt++;
    sleep(1);
  }

}


