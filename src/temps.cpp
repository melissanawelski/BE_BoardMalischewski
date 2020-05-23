#include "temps.h"

using namespace std;

//exceptions
enum tempserr{overflow_err};

//classe Temps
temps::temps(int min,int h): minute(min), heure(h){};

temps::temps(const temps& autre) : temps(autre.minute, autre.heure) {};

void temps::affiche() const {
    // affichage
    cout << "Heures :";
    cout << heure << ' '<<'\n';
    cout << "Minute";
    cout << minute << ' '<<'\n';
}

void temps::put(){
     int i; // compteur interne
    // saisie
    cout << "taper les heures ";
    cin >> heure;
    cout << "taper les minutes ";
    cin >> minute;
}

    //operateurs
temps& temps::operator = (const temps& tempsbis){
    NULL;
}

temps& temps::operator +=(const temps& tempsbis){
    NULL;
}


//opérateur d'incrémentation
temps operator + (const temps& temps1, const temps& temps2);
