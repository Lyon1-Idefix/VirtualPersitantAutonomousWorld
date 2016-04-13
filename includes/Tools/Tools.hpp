#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <ctime>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <vector>

template<typename T>
T rand(T min, T max){
	srand (std::time(0) + (int)(rand()*10));

	return min + (T)rand()/((T)RAND_MAX/(T)((max+1)-min));
}

std::string getRandomMaleName();
std::string getRandomFemaleName();
std::vector<std::string> cutString(std::string & str, std::string delimiter);

#endif
