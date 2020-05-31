#include "maison.h"

using namespace std;


//classe Maison
Maison::Maison(){
    cout << "Quel est le nom de votre maison?"<<'\n';
    cin >> nom;
};

Maison::~Maison(){
	NULL;
}


//Initialisation de la maison
 void Maison::initialisationmaison(int nbp){
	int i; //compteur
	char nompiece;
	
	for (i=0; i< nbp; i++){
		cout << "Quel est le nom de la piece"<< i << "?" <<'\n';
		cin >> nompiece;
		Piece piece_aux = Piece(nompiece);
		piece_aux.affichepiece();
		agrandissement(piece_aux);
	} 
} 

//fonction d'affichage de la liste de pièce
void Maison::affiche() {
	int i;//compteur
	cout << "("; //affichage
	for (i = 0; i < nbpiece; i++) {
		cout << liste[i].getnamepiece() << ',';
	}
	cout << ")\n";
}


//fonction de renvoie du nombre de pièce
int Maison::getnbpiece(){
	return nbpiece;
}

void Maison::agrandissement(Piece newp){
		liste.push_back(newp);
}

//opérateur d'affectation
 Maison& Maison::operator = (Maison& mbis) {
	if (nbpiece != mbis.nbpiece) {
		cout << "elles n ont pas le meme nombre de piece";
	}else{
		int i;
		for (i=0; i<nbpiece; i++){
			liste[i]=mbis.liste[i];
		}
	}
    nbpiece=mbis.nbpiece;
	return (*this);
} 

  //opérateur arithmétique, concatène deux maisons
Maison& Maison::operator += (const Maison& mbis) {
	int i;
    int nbpieceajoutee=nbpiece-mbis.nbpiece;
	for (i = 0; i < nbpieceajoutee; i++){
		liste.push_back(mbis.liste[i]);
	}
	return(*this);
} 

//opérateur d'indiçage
Piece& Maison::operator [] ( int i) {
	if (i > (nbpiece - 1) || i < 0) {
		cout << "le numero d'indice n est pas le bon";
	}
	return(liste[i]);
} 

