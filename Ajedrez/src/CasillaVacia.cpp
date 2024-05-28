#include "CasillaVacia.h"
#include <iostream>

void CasillaVacia::print() {

	std::cout << ((color_casilla == NEGRO) ? "_" : "_");
}

