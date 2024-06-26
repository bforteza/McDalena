#include "Peon.h"
#include "Tablero.h"

VectorCoordenadas Peon::premove(Tablero* tablero, const Coordenadas& posicion)
{
	VectorCoordenadas retorno;
	Coordenadas dir(posicion);

	if (color == BLANCO)
		dir.fil += 1;
	else dir.fil += -1;

	if (dir < tablero->get_tam()
		&& tablero->get_pieza(dir) == nullptr) {
		retorno += dir;
	}

	dir.col += 1;
	if (dir < tablero->get_tam()
		&& tablero->get_pieza(dir) != nullptr
		&& tablero->get_pieza(dir)->get_color() != color) {
		retorno += dir;
	}

	dir.col += -2;
	if (dir < tablero->get_tam()
		&& tablero->get_pieza(dir) != nullptr
		&& tablero->get_pieza(dir)->get_color() != color) {
		retorno += dir;
	}

	return retorno;
}

void Peon::gpieza(std::ofstream& out) const {
	out << static_cast<int>(color);
	out << " " << tipo << std::endl;
}