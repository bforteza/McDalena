#include "Alfil.h"

void Alfil::print() {

	std::cout << ((color == NEGRO) ? "B" : "b");
}

VectorCoordenadas Alfil::premove(Tablero* tablero, const Coordenadas& posicion)
{
	Coordenadas direcciones[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };

	return Pieza::premove_dir(direcciones, tablero, posicion);
	
}
