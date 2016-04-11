#include "Noeud.hpp"

Noeud::Noeud() {}
Noeud::Noeud(Action* a) : action(a){}
Noeud::Noeud(Noeud* n) : arretesOut(n->arretesOut), arretesIn(n->arretesIn), action(n->action){}

void Noeud::setAction(Action * a) {
    action = a;
}

Action * Noeud::getAction(){
    return action;
}

Noeud * Noeud::executerNoeud(Sentient_Entity * a){
}
