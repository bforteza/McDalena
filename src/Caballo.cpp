#include "Caballo.h"

void Caballo::print() {

	std::cout << ((color == NEGRO) ? "N" : "n");
}

VectorCoordenadas Caballo::premove(const Tablero* const tablero, const Coordenadas& posicion)
{
	return VectorCoordenadas();
}

