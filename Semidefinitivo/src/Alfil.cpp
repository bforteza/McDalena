#include "Alfil.h"



VectorCoordenadas Alfil::premove(Tablero* tablero, const Coordenadas& posicion)
{
	Coordenadas direcciones[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };

	return Pieza::premove_dir(direcciones, tablero, posicion);

}

void Alfil::gpieza(std::ofstream& out) const {
	out << static_cast<int>(color) << tipo << std::endl;
}