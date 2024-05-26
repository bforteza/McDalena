#include "Alfil.h"
#include "Torre.h"

void Alfil::print() {

	std::cout << ((color_pieza == NEGRO) ? "B" : "b");
}