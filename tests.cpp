/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

void Tests::tests_unitaires_formes()
{
    // Tests sur les formes geometriques

    // Formes utilisées pour les tests
    int x = 3;
    int y = 2;
    int l = 5;
    int h = 8;
    Forme *forme = new Rectangle(x, y, l, h);

    // Forme::getAncrage()
    if (forme->getAncrage().x != x || forme->getAncrage().y != y)
        cout << "Erreur: Rectangle::getAncrage() - Mauvaise valeur retournée après instantiation" << endl;

    // Forme::translater()
    int deltaX = 2;
    int deltaY = -3;
    forme->translater(deltaX, deltaY);
    if (forme->getAncrage().x != x + deltaX || forme->getAncrage().y != y + deltaY)
        cout << "Erreur: Rectangle::translater() - Mauvaise valeur retournée après translation" << endl;

    // Forme::aire() (Rectangle)
    if (forme->aire() != l * h)
        cout << "Erreur: Rectangle::aire() - Mauvaise valeur retournée" << endl;

    cout << "TERMINÉ - tests_unitaires_formes" << endl;
}

void Tests::tests_unitaires_vecteur()
{
    // Tests sur la classe Vecteur
}

void Tests::tests_unitaires_couche()
{
    // Tests sur la classe Couche
}

void Tests::tests_unitaires_canevas()
{
    // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
    // Fait tous les tests unitaires
    tests_unitaires_formes();
    tests_unitaires_vecteur();
    tests_unitaires_couche();
    tests_unitaires_canevas();
}

void Tests::tests_application()
{
    // Fait tous les tests applicatifs
    tests_application_cas_01();
    tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
    cout << "TESTS APPLICATION (CAS 01)" << endl;
    // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
    cout << "TESTS APPLICATION (CAS 02)" << endl;
    // Il faut ajouter les operations realisant ce scenario de test.
}
