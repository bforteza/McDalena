#include "Reina.h"


VectorCoordenadas Reina::premove(Tablero* tablero, const Coordenadas& posicion)
{
	Coordenadas direccionest[4] = { {0,1},{0,-1},{1,0},{-1,0} };
	Coordenadas direccionesa[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };

	return  (Pieza::premove_dir(direccionest, tablero, posicion)
		+ Pieza::premove_dir(direccionesa, tablero, posicion));
}

void Reina::gpieza(std::ofstream& out) const {
	out << static_cast<int>(color);
	out << " " << tipo << std::endl;
}