#include <iostream>
#include "ia/Entity/Insentient_Entity.hpp"

Insentient_Entity::Insentient_Entity(std::string n, type tid, std::map<int, int> charac, int o, int x, int y) : Tangible_Entity(n, tid, charac, Position(x, y)) {}

int Insentient_Entity::getValById(int id) {
	if (characteristics.find(id) == characteristics.end()) {
		return -1;
	}
	return characteristics.at(id);
}

int Insentient_Entity::setValById(int id, int v) {
	//si la clé n'existe pas on fait rien
	if (characteristics.find(id) == characteristics.end()) {
		return -1;
	}
	//sinon on met à jour la valeur de la clé existante

	characteristics.at(id) = v;
	return 1;
}

void Insentient_Entity::updateResource(unsigned int wstime) {
	if (typeId == ID_RESSOURCE) {
		if (this->getVal(C_RESPAWN_RATE) != 0 && (wstime % this->getVal(C_RESPAWN_RATE)) == 0) {
			Characteristics * c = Characteristics::getCharacById(Characs::C_MAXRESSTOCK);
			for (auto it = stock.begin(); it != stock.end(); it++) {
				if (it->second < c->getMax()) {
					it->second = it->second + this->getVal(C_RESPAWN_VALUE);
				}
				if (it->second >= c->getMax()) {
					it->second = c->getMax();
				}
			}
		}
	}
}

void Insentient_Entity::affiche(){

}

cJSON* Insentient_Entity::toJson(){
		cJSON * tangible_entity = Tangible_Entity::toJson();
		return tangible_entity;
}
