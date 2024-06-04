#include "CasillaVacia.h"
#include <iostream>


void CasillaVacia::set_verde()
{
	verde = true;

}

void CasillaVacia::set_rojo()
{
	rojo = true;
}

void CasillaVacia::print(const float x, const float y, const float lado) {


	if (color == NEGRO)
	{
		sprite_casilla = new Sprite("bin/imagenes/cuadrado2.png", x, y, lado , lado);
	}
	if (color == BLANCO)
	{
		sprite_casilla = new Sprite("bin/imagenes/cuadrado.png", x, y, lado , lado);
	}
	if (verde)
	{
		sprite_casilla = new Sprite("bin/imagenes/cuadradoverde.png", x, y, lado , lado);
		verde = false;
	}
	if (rojo)
	{
		sprite_casilla = new Sprite("bin/imagenes/cuadradorojo.png", x,y ,lado, lado);
		rojo = false;
	}


	sprite_casilla->draw();

}
