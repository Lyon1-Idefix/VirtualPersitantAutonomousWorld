#include <iostream>
#include "ia/Entity/Entity.hpp"
#include "ia/Entity/Characteristics.hpp"

unsigned int Entity::idCount = 0;

Entity::Entity(std::string n, type tid, std::map<int, int> charac) : typeId(tid), name(n), charact_correspondence(charac), modif(false), idle(true) {
	id = idCount;
	idCount++;
}

unsigned int Entity::getId() {
	return id;
}

std::string Entity::getName() {
	return name;
}

void Entity::setName(std::string n) {
	name = n;
	setModif(true);
}

type Entity::getTypeId() {
	return typeId;
}

bool Entity::getModif() {
	return modif;
}

bool Entity::getIdle() {
	return idle;
}

void Entity::setModif(bool m) {
	modif = m;
}

void Entity::setIdle(bool i) {
	idle = i;
	setModif(true);
}

int Entity::getVal(int id) {
	if (charact_correspondence.find(id) == charact_correspondence.end()) {
		return -1;
	}
	return charact_correspondence.at(id);
}

int Entity::setVal(int id, int v) {
	//si la clé n'existe pas on fait rien
	if (getVal(id) == -1) {
		return -1;
	}
	//sinon on met à jour la valeur de la clé existante
	if (v <= Characteristics::listCharacteristics[id].getMax() && v >= Characteristics::listCharacteristics[id].getMin()) {
		charact_correspondence.at(id) = v;
		Characteristics::listCharacteristics[id].setModif(true);
		// modif = true;
		return 1;
	}
	if (v > Characteristics::listCharacteristics[id].getMax()) {
		charact_correspondence.at(id) = Characteristics::listCharacteristics[id].getMax();
		Characteristics::listCharacteristics[id].setModif(true);
		// modif = true;
		return -2;
	}
	else {
		charact_correspondence.at(id) = Characteristics::listCharacteristics[id].getMin();
		Characteristics::listCharacteristics[id].setModif(true);
		// modif = true;
		return -3;
	}
}

void Entity::decade(unsigned int wstime) {
	if (wstime % getVal(C_SATIETY_DECADE) == 0) {
		int sat_dec_val = getVal(C_SATIETY_DECADE_VALUE);
		if (sat_dec_val != -1) {
			setVal(C_SATIETY, getVal(C_SATIETY) - sat_dec_val);
		}
	}
	//Si l'agent ne fait rien
	if (idle) {
		if (wstime % getVal(C_STAMINA_DECADE) == 0) {
			int sta_dec_val = getVal(C_STAMINA_DECADE_VALUE);
			if (sta_dec_val != -1) {
				setVal(C_STAMINA, getVal(C_STAMINA) + (sta_dec_val * 4));
			}
		}
	}
	//Sinon
	else {
		if (wstime % getVal(C_STAMINA_DECADE) == 0) {
			int sta_dec_val = getVal(C_STAMINA_DECADE_VALUE);
			if (sta_dec_val != -1) {
				setVal(C_STAMINA, getVal(C_STAMINA) - sta_dec_val);
			}
		}
	}
}

cJSON* Entity::toJson() {
	/*
	{
		"id": "this->is",
		"typeId": "this->typeId",
		"name": "this->name",
	 */
	cJSON *root;
	root = cJSON_CreateObject();
	cJSON_AddNumberToObject(root, "id", this->id);
	cJSON_AddStringToObject(root, "typeId", TypeNames[this->typeId]);
	cJSON_AddStringToObject(root, "name", this->name.c_str());
	//cout << cJSON_Print(root) << endl;

	return root;
}


unsigned int Entity::isHungry(void) {
	int s = getVal(C_SATIETY);
	int s_t = getVal(C_SATIETY_THRESHOLD);
	if (s >= 0 && s_t >= 0) {
		if (s <= s_t) return 1;
		else if (s > s_t) return 0;
	}
	return -1;
}

unsigned int Entity::isTired(void) {
	int s = getVal(C_STAMINA);
	int s_t = getVal(C_STAMINA_THRESHOLD);
	if (s >= 0 && s_t >= 0) {
		if (s <= s_t) return 1;
		else if (s > s_t) return 0;
	}
	return -1;
}

void Entity::affiche()
{}

Entity::~Entity(void) {}
