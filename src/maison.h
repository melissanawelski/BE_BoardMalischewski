#ifndef MAISON_H
#define MAISON_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <vector>
#include "piece.h"



// classe qui manipule mes maisons
class Maison {
private:
  // nombre de pièce dans la maison
  int nbpiece;
  char nom[15];
  Piece *first;  
  
public:
    //constructeur
    Maison();
    //constructeur de recopie
    Maison(const Maison& autre);

    // destructeur
    virtual ~Maison();

    //operateurs
	  Maison& operator = (const Maison& mbis);
	  Maison& operator +=(const Maison& mbis);
    Piece& operator [](const int i);

    //méthodes (fonctions de la classe)
    void affiche() const; //fonction affichage de la liste des pieces
    void put(); //fonction de saisie des pièces de la maison
    int getnbpiece() const; //renvoie le nombre de pièce 
    void agrandissement(Maison m, Piece newp); //ajoute une pièce à la maison

};

//opérateur d'incrémentation
Maison operator + (const Maison& m1, const Maison& m2);



#endif