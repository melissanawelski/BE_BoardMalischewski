#include <unistd.h>
#include "core_simulation.h"

#define RIDEAUCLOSE 10 // pour teste plus rapide
#define RIDEAUOPEN 20  // pour teste plus rapide
#define TEMPIDEAL 23




// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
  pinMode(0,INPUT);
  // // on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(0,INPUT); // pin sensor_temperature
  pinMode(1,INPUT); // pin sensor_luminosity
  pinMode(2,INPUT); // pin sensor_position
  pinMode(3,INPUT); // pin interaction_button
  pinMode(4,OUTPUT); // pin actuator_led qui indique l etat du button
  pinMode(5,OUTPUT); // pin actuator_moteur
  pinMode(6,OUTPUT); // pin actuator_lampe
  pinMode(7,OUTPUT); // pin actuator_chauffclim
  pinMode(8,INPUT); //pin sensor_presence
  pinMode(9,INPUT); //pin sensor_heuredormir
  // on initialise etat du sorties
  digitalWrite(4,LOW); // initialise etat du sortie a LOW
  analogWrite(5,0); // initialise etat du sortie a 0 (device closed)
  analogWrite(6,0); // initialise etat du sortie a 0 (device closed)
  analogWrite(7,0); // initialise etat du sortie a 0 (device closed)
}

// la boucle de controle arduino
void Board::loop(){
// // recuperer et afficher la valeur du temperature et lumonosite
  char bufTem[100];
  char bufLum[100];
  char bufPos[100];
  int valTem; // valeurs de temperature
  int valLum; // valeurs de lunimosite
  int valPos; //valeurs de position
  int etatPresence;
  int etatJour;
  int etatButton = 0;
  int level=0; 
  static int cpt=0;


  for(int i=0;i<10;i++){
    // lecture sur les pins
    valTem=analogRead(0); // lire les valeurs des capteurs
    valLum=analogRead(1);
    valPos=analogRead(2);
    etatButton=digitalRead(3);   
    etatPresence=digitalRead(8);
    etatJour=digitalRead(9);
    // allume ou etteint led pour indiquer l etat du button : button on -> allume, button off ->etteint  
    if(etatButton==1)
      digitalWrite(4,HIGH);
    else digitalWrite(4,LOW);
    // surveille les donnes
    sprintf(bufTem,"temperature %d",valTem);
    Serial.println(bufTem);
    sprintf(bufLum,"luminosity %d",valLum);
    Serial.println(bufLum);
    sprintf(bufPos,"position du rideau %d",valPos);
    Serial.println(bufPos);
    // tous les 5 fois on affiche sur l ecran la temperature et la lunimosite
    if(cpt%5==0){
      sprintf(bufTem,"%d",valTem);
      sprintf(bufLum,"%d",valLum);
      bus.write(1,bufTem,100); // ecran 1 affiche temperature
      bus.write(2,bufLum,100); // ecran 2 affiche lunimosite
    }
    cpt++;

    // ***TEST CAS JOURNEE : LUMINOSITY SUPERIEUR A 400 + TEMPERATURE RESTE A 23***
    if(etatPresence==1){
      if(etatJour==1){
        // juge luminosite pour assure lum>=400
        // cas humain autorise de toucher le rideau
        if(valLum<400 && etatButton==LOW){
          analogWrite(5,RIDEAUOPEN);
          if(valLum<250 && valPos==RIDEAUOPEN){
            analogWrite(6,4);
            level=4;
          }
          else if(valLum>=250 && valLum < 300 && valPos==RIDEAUOPEN){
            analogWrite(6,3);
            level=3;
          }
          else if(valLum>=300 && valLum < 350 && valPos==RIDEAUOPEN){
            analogWrite(6,2);
            level=2;
          }
          else if(valLum>=350 && valPos==RIDEAUOPEN){
            analogWrite(6,1);
            level=1;
          }
        }
        // cas humain impose rideau a fermer
        else if(valLum<400 && etatButton==HIGH){
          analogWrite(5,RIDEAUCLOSE);
          if(level==0 && valPos==RIDEAUCLOSE){
            if(valLum<250){
              analogWrite(6,4);
            }
            else if(valLum>=250 && valLum < 300 && valPos==RIDEAUCLOSE){
              analogWrite(6,3);
            }
            else if(valLum>=300 && valLum < 350 && valPos==RIDEAUCLOSE){
              analogWrite(6,2);
            }
            else if(valLum>=350 && valPos==RIDEAUCLOSE){
              analogWrite(6,1);
            }
          }
          else if(level!=0 && valPos==RIDEAUCLOSE){
            if(valLum<250){
              analogWrite(6,4);
            }
            else if(valLum>=250 && valLum<300){
              if(level+3<4)
                analogWrite(6,level+3);
              else
                analogWrite(6,4);
            }
            else if(valLum>=300 && valLum<350){
              if(level+2<4)
                analogWrite(6,level+2);
              else
                analogWrite(6,4);
            }
            else if(valLum>=350){
              if(level+1<5)
                analogWrite(6,level+1);
              else
                analogWrite(6,4);
            }
          }   
        }
        else if(valLum>=400 && etatButton==HIGH){
          analogWrite(5,RIDEAUCLOSE);
          if(valTem<19||valTem>25){
            analogWrite(7,TEMPIDEAL);
          }

        }
        else{
          if(valTem<19||valTem>25){
            analogWrite(7,TEMPIDEAL);
          } 
        }
      }
      else{
      //***CAS NUIT***
        analogWrite(5,RIDEAUCLOSE);
        if((valTem<19||valTem>25) && valPos==RIDEAUCLOSE){
          analogWrite(7,TEMPIDEAL);
        }
      }
    }

    sleep(1); // sleep une seconde
  }







  // ***TEST BUTTON***//
  // int etat=0;
  // etat = digitalRead(4);
  // if(etat==1) digitalWrite(0,HIGH);
  // else digitalWrite(0,LOW);


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