#ifndef ACTIONCOMPORTEMENT_HPP
#define ACTIONCOMPORTEMENT_HPP

using namespace std;

#include "Behavior/Action.hpp"
//~ #include "Behavior/Comportement.hpp"
#include <utility>

class Comportement;

class ActionComportement : Action {

	private :
		Comportement * comportement;

	public :
		void Executer(Sentient_Entity * agent);
};

#endif
