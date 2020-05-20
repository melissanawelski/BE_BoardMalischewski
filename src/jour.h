#ifndef JOUR_H
#define JOUR_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <vector>



// classe qui manipule le temps
class jour {
private:
  // valeur des minutes du temps ne comprenant pas les heures
    int minute;
  // valeur des heures du temps ne comprenant pas les minutes
    int heure;
  
  
public:
    //constructeur
    jour(int min,int  h);
    //constructeur de recopie
    jour(const jour& autre);

    // destructeur
    virtual ~jour();
    // fonction d'affichage
    void affiche() const;
    // fonction de saisie des elements du temps
    void put();

    //operateurs
	jour& operator = (const jour& jourbis);
	jour& operator +=(const jour& jourbis);
  
};

//opérateur d'incrémentation
jour operator + (const jour& jour1, const jour& jour2);



#endif