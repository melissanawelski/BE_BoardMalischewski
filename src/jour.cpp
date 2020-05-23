#include "jour.h"

using namespace std;

//exceptions
enum tempserr{overflow_err};

//classe Temps
jour::jour(int min,int h): minute(min), heure(h){};

jour::jour(const jour& autre) : jour(autre.minute, autre.heure) {};

void jour::affiche() const {
    // affichage
    cout << "Heures :";
    cout << heure << ' '<<'\n';
    cout << "Minute";
    cout << minute << ' '<<'\n';
}

void jour::put(){
     int i; // compteur interne
    // saisies
    cout << "taper les heures ";
    cin >> heure;
    cout << "taper les minutes ";
    cin >> minute;
}

    //operateurs
jour& jour::operator = (const jour& jourbis){
    NULL;
}

jour& jour::operator +=(const jour& jourbis){
    NULL;
}


//opérateur d'incrémentation
jour operator + (const jour& jour1, const jour& jour2);
