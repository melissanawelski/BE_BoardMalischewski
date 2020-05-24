#include "piece.h"
#include <unistd.h>

using namespace std;

//classe Piece
Piece::Piece(char np): nom_p(np), temperature(0), luminosite(0), psuivant(NULL){};

Piece::Piece(const Piece& autre): Piece(autre.nom_p){};

