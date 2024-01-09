/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

Forme* créer_forme() {
    // Formes utilis�es pour les tests
    int x = 3;
    int y = 2;
    int l = 5;
    int h = 8;
    Forme *forme = new Rectangle(x, y, l, h);

    return forme;
}

void Tests::tests_unitaires_formes()
{
    // Tests sur les formes geometriques

    // Formes utilis�es pour les tests
    int x = 3;
    int y = 2;
    int l = 5;
    int h = 8;
    Forme *forme = new Rectangle(x, y, l, h);

    // Forme::getAncrage()
    if (forme->getAncrage().x != x || forme->getAncrage().y != y)
        cout << "Erreur: Rectangle::getAncrage() - Mauvaise valeur retourn�e apr�s instantiation" << endl;

    // Forme::translater()
    int deltaX = 2;
    int deltaY = -3;
    forme->translater(deltaX, deltaY);
    if (forme->getAncrage().x != x + deltaX || forme->getAncrage().y != y + deltaY)
        cout << "Erreur: Rectangle::translater() - Mauvaise valeur retourn�e apr�s translation" << endl;

    // Forme::aire() (Rectangle)
    if (forme->aire() != l * h)
        cout << "Erreur: Rectangle::aire() - Mauvaise valeur retourn�e" << endl;

    cout << "TERMIN� - tests_unitaires_formes" << endl;
}

void Tests::tests_unitaires_vecteur()
{
    // Tests sur la classe Vecteur
    Vecteur *vecteur = new Vecteur();
    Forme *forme = créer_forme();

    if(vecteur->taille() != 0)
        cout << "Erreur: La taille par défaut devrait être de 0" << endl;

    if(vecteur->ajouterForme(nullptr) != false)
        cout << "Erreur: Lorsque l'on passe nullprt en argument ajouterForme devrait retourner false" << endl;

    if(vecteur->ajouterForme(forme) != true)
        cout << "Erreur: Lorsque l'on passe un Forme en argument ajouterForme devrait retourner true" << endl;

    if(vecteur->estVide() != false)
        cout << "Erreur: Après avoir ajouté une forme la taille devrait être de 1 alors estVide() devrait retourner false" << endl;   

    if(vecteur->taille() != 1)
        cout << "Erreur: Après avoir ajouté une forme la taille devrait être de 1" << endl;

     if(vecteur->obtenirForme(-2) != nullptr) 
        cout << "Erreur: Lorsque l'on passe un nombre plus petit que 0 en argument obtenirForme devrait retourner nullptr" << endl;

    if(vecteur->obtenirForme(1) != nullptr) 
        cout << "Erreur: Lorsque l'on passe un nombre plus grand ou égale à la taille en argument obtenirForme devrait retourner nullptr" << endl;
    
    if(vecteur->obtenirForme(0) != forme) 
        cout << "Erreur: Lorsque l'on passe un nombre plus grand ou égale à 0 et plus petit que la taille en argument obtenirForme devrait retourner la forme" << endl;

    if(vecteur->retirerForme(-2) != nullptr) 
        cout << "Erreur: Lorsque l'on passe un nombre plus petit que 0 en argument retirerForme devrait retourner nullptr" << endl;

    if(vecteur->retirerForme(1) != nullptr) 
        cout << "Erreur: Lorsque l'on passe un nombre plus grand ou égale à la taille en argument retirerForme devrait retourner nullptr" << endl;
    
    if(vecteur->retirerForme(0) != forme) 
        cout << "Erreur: Lorsque l'on passe un nombre plus grand ou égale à 0 et plus petit que la taille en argument retirerForme devrait retourner la forme" << endl;

    if(vecteur->taille() != 0)
        cout << "Erreur: Après avoir retiré une forme la taille devrait être de 0" << endl;

     if(vecteur->estVide() != true)
        cout << "Erreur: Après avoir retiré une forme la taille devrait être de 0" << endl;    

    vecteur->ajouterForme(créer_forme());
    vecteur->ajouterForme(créer_forme());
    vecteur->ajouterForme(créer_forme());
    vecteur->vider();
    if(vecteur->estVide() != true)
        cout << "Erreur: Après avoir appelé vider() il reste des éléments dans le tablau de forme" << endl;    

    if(vecteur->capacite() != 1)
        cout << "Erreur: La capacite par defaut devrait être de 1" << endl;    

    vecteur->doublerCapacite();
    if(vecteur->capacite() != 2)
        cout << "Erreur: La capacite devrait être de 2 puisqu'elle a été doublé 1 fois" << endl;

    vecteur->doublerCapacite();
    if(vecteur->capacite() != 4)
        cout << "Erreur: La capacite devrait être de 4 puisqu'elle a été doublé 2 fois" << endl;      
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
