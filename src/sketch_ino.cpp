#include <unistd.h>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
  // on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  // pinMode(2,INPUT); // pin sensor lunimosity
  // pinMode(3,INPUT);
  pinMode(0,OUTPUT);
  pinMode(4,INPUT);
  //pinMode(3,OUTPUT); // pin intelligent led
  // pinMode(5,OUTPUT);
  // pinMode(6,OUTPUT);
  // analogWrite(5,0);
  // analogWrite(6,0);
  // pinMode(7,OUTPUT);
  // analogWrite(7,0);
  digitalWrite(0,LOW);
}

// la boucle de controle arduino
void Board::loop(){
  // ***TEST BUTTON***//
  int etat=0;
  etat = digitalRead(4);
  if(etat==1) digitalWrite(0,HIGH);
  else digitalWrite(0,LOW);


  // ***TEST LUMINOSITY 400***
  // char bufLum[100];
  // int valLum;
  // char bufPos[100];
  // int valPos;

  // for(int i=0;i<5;i++){
  //   valLum=analogRead(2);
  //   sprintf(bufLum,"luminosity %d",valLum);
  //   Serial.println(bufLum);
  //   valPos=analogRead(3);
  //   sprintf(bufPos,"position du rideau %d",valPos);
  //   Serial.println(bufPos);
  //   sleep(1);
  // }

  // if(valLum<400){
  //   analogWrite(5,90);
  //   if(valLum<250 && valPos==90){
  //     analogWrite(6,4);
  //   }
  //   else if(valLum>=250 && valLum < 300 && valPos==90){
  //     analogWrite(6,3);
  //   }
  //   else if(valLum>=300 && valLum < 350 && valPos==90){
  //     analogWrite(6,2);
  //   }
  //   else if(valLum>=350 && valPos==90){
  //     analogWrite(6,1);
  //   }
  // }
  // else{
  //     cout<<"[[[[[[[[[[[[luminosity bon]]]]]]]]]]]";
  // }


  // ***Codes pour SCREEN si bosion***
  // static int cpt=0;
  // if(cpt%5==1){ // tous les 5 fois on affiche sur l ecran la luminosity
  //   sprintf(bufLum,"%d",valLum);
  //   bus.write(2,bufLum,100);
  //   }
  // cpt++;


  // ***test ChaffClim***
  // char bufTem[100];
  // int valTem;
  // for(int i=0;i<5;i++){
  //   valTem=analogRead(1);
  //   sprintf(bufTem,"temperature %d",valTem);
  //   Serial.println(bufTem);
  //   sleep(1);
  // }
  // analogWrite(7,21);

    

}