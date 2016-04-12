#include <iostream>

#include "Characteristics.hpp"
#include "Factories.hpp"
#include "Comportement.hpp"
#include "Sentient_Entity.hpp"

void scenario(){
    std::string name = "Mykaz";
    std::string tid = "agent";
    Sentient_Entity* agent = new Sentient_Entity(Position(0, 0),name,tid);
    Comportement comp;
    Noeud noeudPasFaim;
    Noeud noeudFaim;

    std::vector<Fonction_Bool> vecteur1;
    vecteur1.push_back(Fonction_BOOL_TRUE);
    Arete aretePasFaim(&noeudPasFaim,&noeudFaim,vecteur1);

    std::vector<Fonction_Bool> vecteur2;
    vecteur2.push_back(Fonction_BOOL_FALSE);
    Arete areteFaim(&noeudFaim,&noeudPasFaim,vecteur2);

    std::vector<Arete*> vecteurArete1;
    vecteurArete1.push_back(&aretePasFaim);
    std::vector<Arete*> vecteurArete2;
    vecteurArete2.push_back(&areteFaim);

    noeudPasFaim.setAretesIn(vecteurArete2);
    noeudPasFaim.setAretesOut(vecteurArete1);
    noeudFaim.setAretesIn(vecteurArete1);
    noeudFaim.setAretesOut(vecteurArete2);

    Noeud* noeudCourant = &noeudPasFaim;

    comp.ajouterNoeud(&noeudPasFaim);
    comp.ajouterNoeud(&noeudFaim);

    std::cout << "Noeud courant : " << noeudCourant << std::endl;
    noeudCourant = noeudCourant->executerNoeud(agent);
    std::cout << "Noeud Courant apres : " << noeudCourant << std::endl;
}

int main(int argc, char const *argv[])
{

    scenario();

    return 0;
}
