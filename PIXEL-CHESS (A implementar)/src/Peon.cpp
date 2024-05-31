#include "Peon.h"
#include "Tablero.h"
#include <iostream>

void Peon::print(int col, int fil, double origenx, double origeny) {

	
	//std::cout << ((color_pieza == NEGRO) ? "P" : "p");

	if (color_casilla == NEGRO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/PeonN.png", fil * 1.072 - 1.62, -1.072 * col + 2.45, 0.8, 0.8);
		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/PeonB.png", fil * 1.072 - 1.65, -1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	if (color_casilla == BLANCO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/PeonN.png", fil * 1.072 - 1.62, -1.072 * col + 2.45, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/PeonB.png", fil * 1.072 - 1.65, -1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	sprite_pieza->draw();
	sprite_casilla->draw();

}

bool Peon::premove(Tablero* tablero, int col, int fil) {
	bool retorno = false;
	int dir = (color_pieza == BLANCO) ? +1 : -1;
	
	Casilla* aux = tablero->get_casilla(col, fil + dir);
	if (aux != nullptr && !aux->ocupado()) {
		aux->selecionada = true;
		retorno = true;
	}
	for (int i = -1; i <= 1; i += 2) {
		aux = tablero->get_casilla(col + i, fil + dir);
		if (aux != nullptr && 
		(aux->ocupado() && dynamic_cast<Pieza*>(aux)->get_color_pieza() != color_pieza)) {
			aux->selecionada = true;
			retorno = true;
		}
	}

	return retorno;
		
}