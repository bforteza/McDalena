#include "Caballo.h"

void Caballo::print(int col, int fil, double origenx, double origeny) {

	if (color == NEGRO)
	{
		sprite_pieza = new Sprite("imagenes/CaballoN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

	}
	if (color == BLANCO)
	{
		sprite_pieza = new Sprite("imagenes/CaballoB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

	}
	sprite_pieza->draw();
}

VectorCoordenadas Caballo::premove(Tablero* tablero, const Coordenadas& posicion)
{
	return VectorCoordenadas();
}




