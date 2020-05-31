#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>

using namespace std;

// classe qui manipule mes pieces
class Piece {
public:
    //constructeur
    Piece(char np);
    //constructeur de recopie
    Piece(const Piece& autre);

    // destructeur
    //~Piece();

    //renvoie le nom de la pièce
    char getnamepiece(){
      return nom_p;
    }

    void affichepiece(){
      cout << "la temperature est : "<< temperature << '\n';
      cout << "la luminosite est : " << luminosite << '\n';
      cout << "le nom de la piece est :" << nom_p << '\n';
    }

  
  
  private:
  // temperature
    int temperature;
  //luminosité
    int luminosite;
  //nom de la pièce
    char nom_p;
    
 
};


#endif