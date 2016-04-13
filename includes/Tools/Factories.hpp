#ifndef FACTORIES_HPP
#define FACTORIES_HPP

#include <fstream>
#include <iostream>
#include "Entity/Characteristics.hpp"
#include "Entity/Sentient_Entity.hpp"
#include "Tools/Tools.hpp"

class Factories{

public:

	//Factories permettant de créer les entités conscientes

	static Sentient_Entity * createAgent();
	
	static Sentient_Entity * createAnimal();

};

#endif
