#include "Alfil.h"

void Alfil::print( const float x, const float y, const float lado) {

	//std::cout << ((color_pieza == NEGRO) ? "A" : "a");
		if (color == NEGRO)
		{
			sprite_pieza = new Sprite("bin/imagenes/AlfilN.png",x, y, lado , lado);
		}
		if (color == BLANCO)
		{
			sprite_pieza = new Sprite("bin/imagenes/AlfilB.png",x, y, lado , lado);

		}

	sprite_pieza->draw();



}

VectorCoordenadas Alfil::premove(Tablero* tablero, const Coordenadas& posicion)
{
	Coordenadas direcciones[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };

	return Pieza::premove_dir(direcciones, tablero, posicion);

}
