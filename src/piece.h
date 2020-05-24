#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <vector>


// classe qui manipule mes pieces
class Piece {
private:
  // temperature
    int temperature;
  //luminosité
    int luminosite;
  //nom de la pièce
    char nom_p;
    //piece suivante;
    Piece *psuivant;

public:
    //constructeur
    Piece(char np);
    //constructeur de recopie
    Piece(const Piece& autre);

    // destructeur
    virtual ~Piece();

    //renvoie le nom de la pièce
    char getnamepiece(){
        return nom_p;
    }

    Piece* getsuivantpiece(){
        return psuivant;
    }

    void putnamepiece(char n){
        nom_p=n;
    }
 
};


#endif