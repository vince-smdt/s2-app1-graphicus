#include "tests.h"

int main() {
    setlocale(LC_ALL, "");

    // Tests tests;
    // tests.tests_unitaires();

    Canevas c;

    c.activerCouche(0);
    c.ajouterForme(new Rectangle(2, 3, 1, 1));
    c.ajouterForme(new Carre(0, 0, 3));
    c.ajouterForme(new Cercle(7, 8, 6));

    c.activerCouche(2);
    c.ajouterForme(new Rectangle(5, 6, 3, 4));
    c.ajouterForme(new Carre(3, 4, 1));
    c.ajouterForme(new Cercle(0, 0, 3));

    c.activerCouche(3);
    c.ajouterForme(new Cercle(-3, 6, 1));

    c.activerCouche(0);

    c.afficher(cout);

    return cin.get();
}