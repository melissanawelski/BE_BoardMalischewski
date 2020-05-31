#ifndef MAISON_H
#define MAISON_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <vector>
#include "piece.h"
using namespace std;



// classe qui manipule mes maisons
class Maison {
public:
  // nombre de pièce dans la maison
  int nbpiece;
  char nom;
  vector<Piece> liste;
   
  
public:
    //constructeur
    Maison();
    //constructeur de recopie
    Maison(const Maison& autre);

    // destructeur
    ~Maison();

    //operateurs
	  Maison& operator = (Maison& mbis);
	  Maison& operator += (const Maison& mbis);
    Piece& operator [](int i);

    //méthodes (fonctions de la classe)
    void initialisationmaison(int nbp); //initialise la maison de l'utilisateur
    void affiche(); //fonction affichage de la liste des pieces
    int getnbpiece(); //renvoie le nombre de pièce 
    void agrandissement(Piece newp); //ajoute une pièce à la maison
    

};




#endif