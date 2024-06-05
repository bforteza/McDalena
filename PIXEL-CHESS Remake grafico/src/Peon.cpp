#include "Peon.h"
#include "Tablero.h"
void Peon::print(int col, int fil, double origenx, double origeny) {

		if (color == NEGRO)
		{
			sprite_pieza = new Sprite("imagenes/PeonN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
		if (color == BLANCO)
		{
			sprite_pieza = new Sprite("imagenes/PeonB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
	sprite_pieza->draw();
}

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
	out << static_cast<int>(color) << tipo << std::endl;
}
