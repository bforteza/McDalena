#include "Reina.h"
#include <iostream>

void Reina::print() {

	std::cout << ((color_pieza == NEGRO) ? "Q" : "q");
}