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
  int vappui;
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

  for(i=0;i<5;i++){
    // lecture sur la pin 2 : capteur de temperature
    valLum=analogRead(2);
    sprintf(buf,"luminosity %d",valLum);
    Serial.println(buf);

    if(cpt%5==0){
        // tous les 5 fois on affiche sur l ecran la temperature
      sprintf(buf,"%d",valLum);
      bus.write(1,buf,100);
    }
    cpt++;
    sleep(1);
  } 
  
  for(i=0;i<5;i++){
    // lecture sur la pin 4 : bouton
    vappui=analogRead(4);
    sprintf(buf,"button %d",vappui);
    Serial.println(buf);

    if(cpt%5==0){
        //toutes les 5 fois on affiche sur l ecran l etat du bouton
      sprintf(buf,"%d",vappui);
      bus.write(1,buf,100);
    }
    cpt++;
    sleep(1);
  }  




// on eteint et on allume la LED
  if(bascule)
    digitalWrite(0,HIGH);
  else
    digitalWrite(0,LOW);
  bascule=1-bascule;
  
}


