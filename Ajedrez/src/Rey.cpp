#include "Rey.h"
#include <iostream>

void Rey::print() {

	std::cout << ((color_pieza == NEGRO) ? "K" : "k");
}