#include "Peon.h"
#include "Tablero.h"
void Peon::print( const float x, const float y, const float lado) {

		if (color == NEGRO)
		{
			sprite_pieza = new Sprite("bin/imagenes/PeonN.png", x, y, lado , lado);

		}
		if (color == BLANCO)
		{
			sprite_pieza = new Sprite("bin/imagenes/PeonB.png", x, y, lado , lado);

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
