#include "maison.h"

using namespace std;

//exceptions
enum piece_err{overunderflow};

//classe Maison
Maison::Maison(): nbpiece(0), first(NULL){
    cout << "Quel est le nom de votre maison?"<<'\n';
    cin >> nom;
};


//fonction d'affichage de la liste de pièce
void Maison::affiche() const {
	int i;//compteur
	cout << "("; //affichage
	for (i = 0; i < nbpiece; i++) {
		cout << first[i].getnamepiece() << ' ';
	}
	cout << ")\n";
}

//fonction de saisie des pièces de la maison
void Maison::put() {
	int i; //compteur
    char n;
	for (i = 0; i < nbpiece; i++) {
		cout << "taper le nom de la" << i + 1 << "ieme pièce :";
		cin >> n;
        first[i].putnamepiece(n);
	}
}

//fonction de renvoie du nombre de pièce
int Maison::getnbpiece() const {
	return nbpiece;
}

void Maison::agrandissement(Maison m, Piece newp){
    if (nbpiece == 0) {
		*first=newp;
	}
    else{
    int i;//compteur
    Piece *pposition = m.first;
    for (i=0; i<nbpiece-1; i++){
        pposition=pposition->getsuivantpiece();
    }
    *pposition->getsuivantpiece()=newp;
    }
}

//opérateur d'affectation
Maison& Maison::operator = (const Maison& mbis) {
	if (nbpiece != mbis.nbpiece) {
		throw overunderflow;
	}
	memcpy(first, mbis.first, nbpiece * sizeof(float));
    nbpiece=mbis.nbpiece;
	return (*this);
}

//opérateur arithmétique, concatène deux maisons
Maison& Maison::operator +=(const Maison& mbis) {
	int i;
    int nbpieceajoutee=nbpiece-mbis.nbpiece;
	for (i = 0; i < nbpieceajoutee; i++)
	{
		agrandissement(mbis,first[i]);
	}
	return(*this);
}

//opérateur d'indiçage
Piece& Maison::operator [] (const int i) {
	if (i > (nbpiece - 1) || i < 0) {
		throw overunderflow;
	}
	return(first[i]);
}


//addition
Maison operator + (const Maison & m1, const Maison & m2) {
	Maison temp_m(m1);
	temp_m += m2;
	return(temp_m);
}