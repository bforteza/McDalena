#include "Peon.h"
#include <iostream>

void Peon::print() {

	std::cout << ((color_pieza == NEGRO) ? "P" : "p");
}