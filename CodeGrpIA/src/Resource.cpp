#include <iostream>
#include "Resource.hpp"
#include <sstream>

unsigned int Resource::idCount = 0;

Resource::Resource(unsigned int rr, unsigned int rv, std::string n)
	: Insentient_Entity(n), respawn_rate(rr), respawn_value(rv)
{
	std::stringstream ss;
	ss << "res_" << Resource::idCount;
	id = ss.str();
	std::cout << id << std::endl;
	Resource::idCount++;
}

