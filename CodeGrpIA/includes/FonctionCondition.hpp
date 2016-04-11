#ifndef FUNCTION_CONDITION_HPP
#define FUNCTION_CONDITION_HPP

#include <iostream>
#include <map>

#include "Sentient_Entity.hpp"

using namespace std;

typedef enum {
	Fonction_BOOL_TRUE,
	Fonction_BOOL_FALSE
} Fonction_Bool;

typedef enum {
	Fonction_INT_1,
	Fonction_INT_2,
	Fonction_INT_3,
	Fonction_INT_4,
	FONC_NULL
} Fonction_Int;

class FonctionCondition {
	public :
		static map<Fonction_Bool,bool(*)(Sentient_Entity * a)> mapFonctionsBool;
		static map<Fonction_Int,int(*)(Sentient_Entity * a, Entity * e)> mapFonctionsInt;
};

typedef enum {
	Inf,
	Inf_Eg,
	Eg,
	Sup_Eg,
	Sup,
	OP_NULL
} Operator;

struct struct_condition{
	Fonction_Int fonc1;
	Entity * e1;
	Operator op;
	Fonction_Int fonc2;
	Entity * e2;
	int comp;
};

bool fonction_true(Sentient_Entity * a);
bool fonction_false(Sentient_Entity * a);

#endif
