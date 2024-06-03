#include "Reina.h"
#include "Tablero.h"
#include <iostream>

void Reina::print(int col, int fil, double origenx, double origeny) {

	//std::cout << ((color_pieza == NEGRO) ? "Q" : "q");

	if (color_casilla == NEGRO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReinaN.png", 1.66 + origenx + fil * 1.072 - 1.62, -2.5 + origeny - 1.072 * col + 2.45, 0.8, 0.8);
		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReinaB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	if (color_casilla == BLANCO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReinaN.png", 1.66 + origenx + fil * 1.072 - 1.62, -2.5 + origeny - 1.072 * col + 2.45, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReinaB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	if (color_casilla == VERDE)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReinaN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReinaB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
	}
	if (color_casilla == ROJO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReinaN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReinaB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
	}
	sprite_pieza->draw();
	sprite_casilla->draw();

}

bool Reina::premove( Tablero* tablero, int col, int fil) {
	bool retorno = false;

	if(color_pieza == BLANCO){

		if (tablero->contador % 2 == 0) {

			retorno = false;
		}

		else if(tablero->contador % 2 != 0){

	retorno = Alfil(BLANCO).premove(tablero, col, fil) &&
	Torre(BLANCO).premove(tablero, col, fil);
	//La reina puede moverse como el alfil y el rey, pues llamo a las funciones premove de ambos y que se ejecuten
	return retorno;
	
	}
	}

	else if (color_pieza == NEGRO) {

		if (tablero->contador % 2 != 0) {

			retorno = false;
		}

		else if (tablero->contador % 2 == 0) {

			retorno = Alfil(NEGRO).premove(tablero, col, fil) &&
				Torre(NEGRO).premove(tablero, col, fil);
			//La reina puede moverse como el alfil y el rey, pues llamo a las funciones premove de ambos y que se ejecuten
			return retorno;

		}
	}
}


void Reina::mover(Tablero* tablero, int posx, int posy, int cvx, int cvy) {

	if (color_pieza == BLANCO) {

		tablero->asignar(posx, posy, new Reina(BLANCO));

		if (posx != cvy || posy != cvx) {

			tablero->contador++;


		}
	}

	else if (color_pieza == NEGRO) {

		tablero->asignar(posx, posy, new Reina(NEGRO));
		if (posx != cvy || posy != cvx) {

			tablero->contador++;


		}
	}


	if (posx != cvy || posy != cvx) {

		tablero->asignar(cvy, cvx, new CasillaVacia(BLANCO));


	}


}