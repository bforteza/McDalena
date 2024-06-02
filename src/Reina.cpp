#include "Reina.h"

void Reina::print() {

	std::cout << ((color == NEGRO) ? "Q" : "q");
}

VectorCoordenadas Reina::premove(const Tablero* const tablero, const Coordenadas& posicion)
{
	Coordenadas direccionest[4] = { {0,1},{0,-1},{1,0},{-1,0} };
	Coordenadas direccionesa[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };
	
	return  (Pieza::premove_dir(direccionest, tablero, posicion)
		+ Pieza::premove_dir(direccionesa, tablero, posicion));
}
