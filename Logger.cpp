#include <iostream>

#include "debug.h"

using namespace debug;

template<typename T>
void debug::log(T type) 
{
	std::cout << type << std::endl;
}