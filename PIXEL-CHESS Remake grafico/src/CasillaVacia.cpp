#include "CasillaVacia.h"
#include <iostream>


void CasillaVacia::print(int col, int fil, double origenx, double origeny) {


	if (color == NEGRO)
	{
		sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
	}
	if (color == BLANCO)
	{
		sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
	}
	if (color == VERDE)
	{
		sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
	}
	if (color == ROJO)
	{
		sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
	}


	sprite_casilla->draw();

}