#include "Caballo.h"

void Caballo::print() {

	std::cout << ((color == NEGRO) ? "N" : "n");
}

VectorCoordenadas Caballo::premove(Tablero* tablero, const Coordenadas& posicion)
{
	return VectorCoordenadas();
}

