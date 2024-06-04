#include "Reina.h"

void Reina::print( const float x, const float y, const float lado) {

	if (color == NEGRO)
	{
		sprite_pieza = new Sprite("bin/imagenes/ReinaN.png", x, y, lado , lado );

	}
	if (color == BLANCO)
	{
		sprite_pieza = new Sprite("bin/imagenes/ReinaN.png", x, y, lado , lado);
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
