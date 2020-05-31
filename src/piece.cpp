#include "piece.h"
#include <unistd.h>

using namespace std;

//classe Piece
Piece::Piece(char np): nom_p(np), temperature(18), luminosite(230){};

Piece::Piece(const Piece& autre): Piece(autre.nom_p){};


