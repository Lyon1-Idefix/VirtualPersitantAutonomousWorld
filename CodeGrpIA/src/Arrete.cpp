#include "Arrete.hpp"

Arrete::Arrete(Noeud * nD, Noeud * nF, vector<Fonction_Bool> fC) : noeudDepart(nD) , noeudFin(nF) {
	//~ conditions = fC;
}

void Arrete::setNoeudDepart(Noeud * nD){
	noeudDepart = nD;
}

void Arrete::setNoeudFin(Noeud * nF){
	noeudFin = nF;
}

Noeud * Arrete::getNoeudDepart(){
	return noeudDepart;
}

Noeud * Arrete::getNoeudFin(){
	return noeudFin;
}

bool Arrete::isTrue(Entity * a){
	for(auto it=conditions_Simples.begin(); it!=conditions_Simples.end(); ++i){
		if(!mapFonctionsBool[*it](a)) return false;
	}
	return true;
}

//~ void Arrete::ajouterCondition(bool (*f)){
	//~ conditions.push_back(f);
//~ }
//~
//~ void Arrete::ajouterCondition(vector<bool (*)> vC){
	//~ for( size_t i=0; i<vC.size(); ++i){
		//~ conditions.push_back(vC[i]);
	//~ }
//~ }

