#include <iostream>
#include <string>
#include <sstream>

#include "serveur_catch.hpp"

#include "Behavior/Action.hpp"
#include "Behavior/ActionComportement.hpp"
#include "Behavior/ActionSimple.hpp"
#include "Behavior/Arete.hpp"
#include "Behavior/Comportement.hpp"
#include "Behavior/EtatEnum.hpp"
#include "Behavior/FonctionEnums.hpp"
#include "Behavior/Noeud.hpp"

#include "Entity/Characteristics.hpp"
#include "Entity/Entity.hpp"
#include "Entity/Insentient_Entity.hpp"
#include "Entity/Item.hpp"
#include "Entity/Sentient_Entity.hpp"
#include "Entity/Tangible_Entity.hpp"
#include "Entity/Tribe.hpp"

#include "Tools/Factories.hpp"
#include "Tools/Position.hpp"
#include "Tools/Astar.hpp"

using namespace std;

TEST_CASE("Test IA", "[ia]")
{
	/*
	SECTION("Scenario 1")
	{
		std::string name = "Mykaz";
		type tid = ID_AGENT;
		Sentient_Entity* agent = new Sentient_Entity(Position(0, 0),name,tid);
		Comportement comp;
		Noeud noeudPasFaim;
		Noeud noeudFaim;
		std::vector<FONC_BOOL> vectFctTrue;
		vectFctTrue.push_back(Fonction_BOOL_TRUE);
		Arete areteTrue(&noeudPasFaim,&noeudFaim);
		std::vector<FONC_BOOL> vectFctFalse;
		vectFctFalse.push_back(Fonction_BOOL_FALSE);
		Arete areteFalse(&noeudFaim,&noeudPasFaim);
		noeudPasFaim.addAreteIn(&areteFalse);
		noeudPasFaim.addAreteOut(&areteTrue);
		noeudFaim.addAreteIn(&areteTrue);
		noeudFaim.addAreteOut(&areteFalse);
		Noeud* noeudCourant = &noeudPasFaim;
		comp.ajouterNoeud(&noeudPasFaim);
		comp.ajouterNoeud(&noeudFaim);
		for(int i = 0; i < 5; i++){
			std::cout << "Noeud courant : " << noeudCourant<< agent->getEtat_Entity() << std::endl;
			agent->setEtat_Entity(3);
			noeudCourant = noeudCourant->executerNoeud(agent);
		}
	}
	*/
	/*
		SECTION("Chargement FICHIER")
		{
			// int loadResult = Characteristics::loadCharacteristicsFile("data/descriptionCharacteristics.txt");
			int loadResult = Characteristics::loadCharacteristicsFile("../../../data/descriptionCharacteristics.txt");
			REQUIRE( loadResult != -1 );
			std::cout << "I loaded the file !" << std::endl;
			for (auto it = begin (Characteristics::listCharacteristics); it != end (Characteristics::listCharacteristics); ++it) {
				std::cout <<it->getType() << std::endl ;
			}
			Sentient_Entity * agent = Factories::createAgent();
			std::cout << agent->getName() << std::endl;
		}
		SECTION("Test de msgpack")
		{
			msgpack::type::tuple<int, bool, std::string> src(1, true, "example");
			// serialize the object into the buffer.
			// any classes that implements write(const char*,size_t) can be a buffer.
			std::stringstream buffer;
			msgpack::pack(buffer, src);
			// send the buffer ...
			buffer.seekg(0);
			// deserialize the buffer into msgpack::object instance.
			std::string str(buffer.str());
			msgpack::object_handle oh =
				msgpack::unpack(str.data(), str.size());
			// deserialized object is valid during the msgpack::object_handle instance is alive.
			msgpack::object deserialized = oh.get();
			// msgpack::object supports ostream.
			std::cout << deserialized << std::endl;
			// convert msgpack::object instance into the original type.
			// if the type is mismatched, it throws msgpack::type_error exception.
			msgpack::type::tuple<int, bool, std::string> dst;
			deserialized.convert(dst);
		}
		SECTION("Test de A*")
		{
		std::cout<<"Test de A*"<<std::endl;
			Sentient_Entity * agent = Factories::createAgent();
			Sentient_Entity * animal = Factories::createAnimal();
			animal->setPos(7,6);
			vector<vector<int>> map;
			std::string line;
		std::ifstream myfile ("../../../data/mapTest.txt", std::ios::in);
		if (myfile.is_open()){
			while(std::getline(myfile,line)){
				if (line != "")
				{
					vector<std::string> resline = cutString(line, ";");
					vector<int> vect;
					for (vector<std::string>::iterator it = resline.begin(); it != resline.end(); it++)
					{
						vect.push_back(stoi(*it));
					}
					map.push_back(vect);
					vect.clear();
				}
			}
			myfile.close();
		}
		else{
			std::cout << "Unable to open file containing map" << std::endl;
		}
		agent->AStar(animal, map);
	    }
	    //~ SECTION("Test de Item + Tribe")
	    //~ {
	   	//~ std::cout<<"Test de Item + Tribe"<<std::endl;
	    	//~ Sentient_Entity * agent = Factories::createAgent();
	    	//~ Sentient_Entity * animal = Factories::createAnimal();
	    	//~ animal->setPos(7,6);
	    	//~
	    	//~ vector<vector<int>> map;
	    	//~
	    	//~ std::string line;
		//~ std::ifstream myfile ("../../../data/mapTest.txt", std::ios::in);
		//~ if (myfile.is_open()){
		//~
			//~ while(std::getline(myfile,line)){
			    //~ if (line != "")
			    //~ {
				    //~ vector<std::string> resline = cutString(line, ";");
				    //~ vector<int> vect;
				    //~ for (vector<std::string>::iterator it = resline.begin(); it != resline.end(); it++)
				    //~ {
				    	//~ vect.push_back(stoi(*it));
				    //~ }
				    //~ map.push_back(vect);
				    //~ vect.clear();
			    //~ }
			//~ }
			//~ myfile.close();
		//~ }
	//~
		//~ else{
			//~ std::cout << "Unable to open file containing map" << std::endl;
		//~ }
		//~
		//~ agent->AStar(animal, map);
	//~
	    //~ }
		}*/

	SECTION("TEST COMPORTEMENT")
	{

            int loadResult = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.txt");

            cout << "ICI, ON TESTE LE COMPORTEMENT" << endl;

            Comportement c;

            Noeud noeudFaimM5;
            Noeud noeudFaimP10;

            Arete areteFaim20(&noeudFaimM5,&noeudFaimP10);
            Arete areteFaim80(&noeudFaimP10,&noeudFaimM5);

            cout << "declaration des Aretes" << endl;

            ActionSimple actionFaimM5;
            ActionSimple actionFaimP10;

            actionFaimM5.setFonc_Void(FONC_FAIM_M5);
            actionFaimP10.setFonc_Void(FONC_FAIM_P10);

            cout << "Setup des Actions" << endl;

            noeudFaimM5.setAction(&actionFaimM5);
            noeudFaimP10.setAction(&actionFaimP10);

            cout << "On a inséré les actions dans les noeuds" << endl;

            noeudFaimM5.ajouterAreteOut(&areteFaim20);
            noeudFaimM5.ajouterAreteIn(&areteFaim80);
            noeudFaimP10.ajouterAreteIn(&areteFaim20);
            noeudFaimP10.ajouterAreteOut(&areteFaim80);

            cout << "On a inséré les aretes dans les noeuds" << endl;

            vector<struct_condition> vecStructCondFaim20;
            struct_condition condFaim20;
            condFaim20.fIE1 = Fonc_GetFaim;
            condFaim20.e1 = nullptr;
            condFaim20.op = Inf;
            condFaim20.comp = 20;
            condFaim20.fIE2 = FONC_I_E_NULL;
            vecStructCondFaim20.push_back(condFaim20);

            cout << "on a mis la condition dans le vecteur" << endl;

            areteFaim20.setCondition_Complexe(vecStructCondFaim20);

            cout << "on a mis le vecteur dans l'arete" << endl;

            vector<struct_condition> vecStructCondFaim80;
            struct_condition condFaim80;
            condFaim80.fIE1 = Fonc_GetFaim;
            condFaim80.e1 = nullptr;
            condFaim80.op = Sup;
            condFaim80.comp = 80;
            condFaim80.fIE2 = FONC_I_E_NULL;
            vecStructCondFaim80.push_back(condFaim80);
            areteFaim80.setCondition_Complexe(vecStructCondFaim80);

            cout << "pareil pour l'autre arete " << endl;

            c.ajouterNoeud(&noeudFaimM5);
            c.ajouterNoeud(&noeudFaimP10);

            cout << "on ajoute les noeuds dans le comportement " << endl;

            Sentient_Entity * agent = Factories::createAgent();

            cout << "on a créé l'agent " << endl;

            agent->addToTrace(&c,&noeudFaimM5,false);

            cout << "on a ajouté le comportement dans l'agent" << endl;

            for(int i=0;i<100;++i){
                cout << endl << "##### iteration " << i << " : " << endl;
                agent->run();
            }

	}

	SECTION("TEST TRIBE")
	{
		cout << "TEST TRIBE" << endl;
		int loadResult = Item::loadItemsFile("../../../data/descriptionItems.txt");

		REQUIRE(Item::listItems.size() != 0);

		Tribe* t = Factories::createTribe();
		REQUIRE(t != NULL);
		t->setName("Anishinaabe");
		REQUIRE(t->getName()=="Anishinaabe");
		t->addItemToStock(&(Item::listItems[1]), 5);

		REQUIRE(t->getQuantityByItem(&(Item::listItems[1])) == 5);
		t->addItemToStock(&(Item::listItems[0]), 10);
		cout<<"Le stock du tribu "<< t->getName() <<" :" << endl;
		t->afficheStock();

		Sentient_Entity * agent = Factories::createAgent();
		cout << "on a créé l'agent " << endl;
		Sentient_Entity * animal = Factories::createAnimal();
		cout << "on a créé l'animal " << endl;
		t->addNewEntity(agent);
		cout<<"on l'a ajouté l'agent dans le tribe" << endl;
		t->addNewEntity(animal);
		cout<<"on l'a ajouté l'animal dans le tribe" << endl;
		cout<<"le nb des entités dans tribe: "<< t->getTribeSize() << endl;

		cout<<"le type de l'entité: " <<agent->getTypeId() <<" -- le type de agent2: "<<animal->getTypeId() <<endl;



	}

	SECTION("TEST ITEM")
	{
		cout << "TEST ITEM" << endl;
		int loadResult = Item::loadItemsFile("../../../data/descriptionItems.txt");

		REQUIRE(Item::listItems.size() != 0);

		Tribe* t = Factories::createTribe();
		REQUIRE(t != NULL);

		t->addItemToStock(&(Item::listItems[0]), 3);

		REQUIRE(t->getQuantityByItem(&(Item::listItems[0])) == 3);

		t->afficheStock();

		Sentient_Entity* ag = Factories::createAgent();
		REQUIRE(ag != NULL);

		ag->addItemToStock(&(Item::listItems[0]), 18);

		REQUIRE(ag->getQuantityByItem(&(Item::listItems[0])) == 18);

		ag->afficheStock();


	}
	
    SECTION("AStar")
    {
		int xDep = 0;
		int yDep = 1;
		int xArr = 5;
		int yArr = 10;
	
		stack<Position> chemin = pathFind(xDep, yDep, xArr, yArr);
		while(!chemin.empty()){
			cout << chemin.top().getX() << ";" << chemin.top().getY() << endl;
			chemin.pop();
		}
    }
	
}
