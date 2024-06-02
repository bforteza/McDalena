#include "Reina.h"

void Reina::print(int col, int fil, double origenx, double origeny) {

	if (color == NEGRO)
	{
		sprite_pieza = new Sprite("imagenes/ReinaN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

	}
	if (color == BLANCO)
	{
		sprite_pieza = new Sprite("imagenes/ReinaB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

	}
	sprite_pieza->draw();
}

VectorCoordenadas Reina::premove(Tablero* tablero, const Coordenadas& posicion)
{
	Coordenadas direccionest[4] = { {0,1},{0,-1},{1,0},{-1,0} };
	Coordenadas direccionesa[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };

	return  (Pieza::premove_dir(direccionest, tablero, posicion)
		+ Pieza::premove_dir(direccionesa, tablero, posicion));
}
