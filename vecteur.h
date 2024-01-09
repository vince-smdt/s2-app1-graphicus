/********
 * Fichier: vecteur.h
 * Auteurs: Vincent Simard-Schmidt & Kevin Gauvin
 * Date: 05 janvier 2024 (creation)
 * Description: Declaration de la classe Vecteur. La classe permet
 *    de stocker plusieurs formes et peut dynamiquement modifier
 *    la taille de son conteneur. Ce fichier fait partie de la
 *    distribution de Graphicus.
********/

#include <iostream>
#include "forme.h"

/*

***** QUESTIONS *****

1. Quelle est la capacite initiale du Vecteur?

2. Lorsque le vecteur est vide, est-ce que le Vecteur retourne a sa capacite initiale
    ou garde-t-il sa capacite actuelle?

*/

#ifndef VECTEUR_H
#define VECTEUR_H

const int CAPACITE_DEPART = 1;

class Vecteur {
public:
    Vecteur();
    ~Vecteur();

    int capacite();
    void doublerCapacite();
    void vider();
    void afficher(ostream &flot);

    int taille();

    bool estVide();
    bool ajouterForme(Forme *forme);

    Forme *retirerForme(int index);
    Forme *obtenirForme(int index);

private:
    Forme **_formes;
    int _taille;
    int _capacite;
};

#endif
