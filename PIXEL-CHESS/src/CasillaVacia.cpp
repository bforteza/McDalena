#include "CasillaVacia.h"
#include <iostream>

void CasillaVacia::print() {


	sprite->draw();
	std::cout << (color_casilla == NEGRO) ? "N" : "B";
}