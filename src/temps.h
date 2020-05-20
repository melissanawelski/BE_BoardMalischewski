#ifndef TEMPS_H
#define TEMPS_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <vector>



// classe qui manipule le temps
class temps {
private:
  // valeur des minutes du temps ne comprenant pas les heures
    int minute;
  // valeur des heures du temps ne comprenant pas les minutes
    int heure;
  
  
public:
    //constructeur
    temps(int min,int  h);
    //constructeur de recopie
    temps(const temps& autre);

    // destructeur
    virtual ~temps();
    // fonction d'affichage
    void affiche() const;
    // fonction de saisie des elements du temps
    void put();

    //operateurs
	temps& operator = (const temps& tempsbis);
	temps& operator +=(const temps& tempsbis);
  
};

//opérateur d'incrémentation
temps operator + (const temps& temps1, const temps& temps2);



#endif