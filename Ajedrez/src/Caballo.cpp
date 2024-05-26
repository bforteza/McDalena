#include <iostream>
#include "Caballo.h"

void Caballo::print() {

	std::cout << ((color_pieza == NEGRO) ? "K" : "k");
}