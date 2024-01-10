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

    if(vecteur->capacite() != 2)
        cout << "Erreur: La capacite par defaut devrait être de 1" << endl;    

    vecteur->doublerCapacite();
    if(vecteur->capacite() != 4)
        cout << "Erreur: La capacite devrait être de 2 puisqu'elle a été doublé 1 fois" << endl;

    vecteur->doublerCapacite();
    if(vecteur->capacite() != 8)
        cout << "Erreur: La capacite devrait être de 4 puisqu'elle a été doublé 2 fois" << endl;      
}

void Tests::tests_unitaires_couche()
{
    // Tests sur la classe Couche
    Couche *couche = new Couche();
    Forme *forme = créer_forme();

    if(couche->getEtat() != Couche::Initialisee)
        cout << "Erreur: L'etat de base devrait être 'Initialisee'" << endl;      

    couche->changerEtat(Couche::Active);
    if(couche->getEtat() != Couche::Active)
            cout << "Erreur: L'etat devrait être 'Active'" << endl;

    couche->changerEtat(Couche::Inactive);
    if(couche->getEtat() != Couche::Inactive)
            cout << "Erreur: L'etat devrait être 'Inactive'" << endl; 

    couche->changerEtat(Couche::Initialisee);
    if(couche->getEtat() != Couche::Initialisee)
            cout << "Erreur: L'etat devrait être 'Initialisee'" << endl;
    
    if(couche->aireTotal() != 0)
        cout << "Erreur: Lorsque l'état est Initialisee airTotal devrait retourner 0" << endl;

    couche->changerEtat(Couche::Active);
    if(couche->ajouterForme(forme) != true)
        cout << "Erreur: Lorsque la couche est Active et que l'on ajoute une forme ajouterForme devrait retourner true" << endl;
    
    if(couche->obtenirForme(0) != forme)
         cout << "Erreur: Lorsque l'on appel obtenirForme() cela devrait retourner la forme de l'index" << endl;

    if(couche->aireTotal() == 0)
        cout << "Erreur: Lorsque l'état est Active airTotal devrait retourner l'air et non 0" << endl;

     if(couche->translater(4, 4) != true)
        cout << "Erreur: Lorsque la couche est Active et que l'on appel translater() le méthode devrait retourner true" << endl;

    if(couche->translater(4, 4) != false)
        cout << "Erreur: Lorsque la couche est Inactive et que l'on appel translater() le méthode devrait retourner false" << endl;
        
    couche->changerEtat(Couche::Inactive);
    if(couche->ajouterForme(forme) != false)
        cout << "Erreur: Lorsque la couche est Inactive et que l'on appel ajouterForme() le méthode devrait retourner false" << endl;


    if(couche->retirerForme(0) != nullptr)
         cout << "Erreur: Lorsque l'on retire une forme d'une couche et que l'état est différent de Active retirerForme() devrait retourner nullptr" << endl;

    couche->changerEtat(Couche::Active);
    if(couche->retirerForme(0) != forme)
         cout << "Erreur: Lorsque l'on retire une forme d'une couche et que l'état est Active retirerForme() devrait retourner la forme retirer" << endl;

    couche->ajouterForme(forme);
    if(couche->reinitialiser() != true)
         cout << "Erreur: reinitialiser() à été appelé et la taille dans forme est différente de 0 " << endl;
}

void Tests::tests_unitaires_canevas()
{
    // Tests sur la classe Canevas
    Canevas *canevas = new Canevas();
    Forme *forme = créer_forme();

    // Par défaut la couche est supposé être active
    if(canevas->ajouterForme(forme) != true)
         cout << "Erreur: lorsque l'on ajoute une forme et que la couche est active cela devrait retourner true" << endl;

    if(canevas->translater(1, 1) != true)
        cout << "Erreur: il devrait être possible de translater une couche active" << endl;

    canevas->desactiverCouche(0);
    if(canevas->ajouterForme(forme) != false)
        cout << "Erreur: lorsque l'on ajoute une forme et que la couche est inactive cela devrait retourner false" << endl;

    if(canevas->translater(1, 1) != false)
        cout << "Erreur: il devrait être possible de translater une couche inactive" << endl;

    if(canevas->aire() < 0)
        cout << "Erreur: L'air devrait être supérieur ou égale à 0" << endl;

    if(canevas->retirerForme(0) != false)
            cout << "Erreur: lorsque l'on retire une forme et que la couche est inactive cela devrait retourner false" << endl;

    canevas->activerCouche(0);
    if(canevas->ajouterForme(forme) != true)
         cout << "Erreur: lorsque l'on retire une forme et que la couche est active cela devrait retourner true" << endl;


    if(canevas->reinitialiserCouche(5) != false)
         cout << "Erreur: lorsque l'on reinitialiserCouche() à un index supérieur au nombre de couche cela doit retourner false" << endl;

    if(canevas->reinitialiserCouche(0) != true)
         cout << "Erreur: lorsque l'on reinitialiserCouche() à un index existant cela doit retourner true" << endl;

    if(canevas->reinitialiser() != true)
         cout << "Erreur: Réinitialiser doit retourner true" << endl;
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
