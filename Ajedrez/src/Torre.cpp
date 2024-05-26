#include "Torre.h"
#include <iostream>

void Torre::print() {

	std::cout << ((color_pieza == NEGRO) ? "K" : "k");
}