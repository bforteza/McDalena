#include "Torre.h"


void Torre::print() {

	std::cout << ((color == NEGRO) ? "R" : "r");
}



VectorCoordenadas Torre::premove(const Tablero* const tablero, const Coordenadas& posicion)
{
	Coordenadas direcciones[4] = { {0,1},{0,-1},{1,0},{-1,0} };

	return Pieza::premove_dir(direcciones,tablero,posicion) ;
}
