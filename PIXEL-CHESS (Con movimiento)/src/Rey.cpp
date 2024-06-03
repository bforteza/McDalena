#include "Rey.h"
#include "Tablero.h"
#include <iostream>
#include "Torre.h"
void Rey::print(int col, int fil, double origenx, double origeny) {

	//std::cout << ((color_pieza == NEGRO) ? "K" : "k");
	if (color_casilla == NEGRO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReyN.png", 1.66 + origenx + fil * 1.072 - 1.62, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);
		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReyB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	if (color_casilla == BLANCO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReyN.png", 1.66 + origenx + fil * 1.072 - 1.62, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReyB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	if (color_casilla == VERDE)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReyN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReyB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
	}
	if (color_casilla == ROJO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReyN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/ReyB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
	}
	sprite_pieza->draw();
	sprite_casilla->draw();


}

bool Rey::premove(Tablero* tablero, int col, int fil) {
	bool retorno = false;
	Casilla* aux;

	if(color_pieza == BLANCO){
		if (tablero->contador % 2 == 0) {

			retorno = false;
		}
		else if (tablero->contador % 2 != 0){
	
	for (int auxcol = col - 1; auxcol <= col + 1; auxcol++) {
		for (int auxfil = fil - 1; auxfil <= fil + 1; auxfil++) { //recorre cuadricula 3x3

			aux = tablero->get_casilla(auxcol, auxfil);

			if (aux != nullptr && !aux->ocupado()) { 
				aux->color_casilla = ROJO;
				aux->selecionada = true;
				retorno = true;
			}
			else if (aux != nullptr && aux->ocupado() && dynamic_cast<Pieza*>(aux)->get_color_pieza() != color_pieza) {
				aux->color_casilla = ROJO;
				aux->selecionada = true;
				retorno = true;
			}

		}
	}

	if (!move) {
		
		if (dynamic_cast<Torre*>(tablero->get_casilla(col + 3, fil)) != nullptr &&
			!dynamic_cast<Torre*>(tablero->get_casilla(col + 3, fil))->get_move() &&
			!tablero->get_casilla(col + 2, fil)->ocupado() && !tablero->get_casilla(col + 1, fil)->ocupado()) {
			tablero->get_casilla(col + 2, fil)->selecionada = true;
		}
		if (dynamic_cast<Torre*>(tablero->get_casilla(col - 3, fil)) != nullptr &&
			!dynamic_cast<Torre*>(tablero->get_casilla(col - 3, fil))->get_move() &&
			!tablero->get_casilla(col - 2, fil)->ocupado() && !tablero->get_casilla(col - 1, fil)->ocupado()) {
			tablero->get_casilla(col - 2, fil)->selecionada = true;
		}

	}
	return retorno;
	}
	}

	else if (color_pieza == NEGRO) {
		if (tablero->contador % 2 != 0) {

			retorno = false;
		}
		else if (tablero->contador % 2 == 0) {

			for (int auxcol = col - 1; auxcol <= col + 1; auxcol++) {
				for (int auxfil = fil - 1; auxfil <= fil + 1; auxfil++) { //recorre cuadricula 3x3

					aux = tablero->get_casilla(auxcol, auxfil);

					if (aux != nullptr && !aux->ocupado()) {
						aux->color_casilla = ROJO;
						aux->selecionada = true;
						retorno = true;
					}
					else if (aux != nullptr && aux->ocupado() && dynamic_cast<Pieza*>(aux)->get_color_pieza() != color_pieza) {
						aux->color_casilla = ROJO;
						aux->selecionada = true;
						retorno = true;
					}

				}
			}

			if (!move) {

				if (dynamic_cast<Torre*>(tablero->get_casilla(col + 3, fil)) != nullptr &&
					!dynamic_cast<Torre*>(tablero->get_casilla(col + 3, fil))->get_move() &&
					!tablero->get_casilla(col + 2, fil)->ocupado() && !tablero->get_casilla(col + 1, fil)->ocupado()) {
					tablero->get_casilla(col + 2, fil)->selecionada = true;
				}
				if (dynamic_cast<Torre*>(tablero->get_casilla(col - 3, fil)) != nullptr &&
					!dynamic_cast<Torre*>(tablero->get_casilla(col - 3, fil))->get_move() &&
					!tablero->get_casilla(col - 2, fil)->ocupado() && !tablero->get_casilla(col - 1, fil)->ocupado()) {
					tablero->get_casilla(col - 2, fil)->selecionada = true;
				}

			}
			return retorno;
		}
	}
}


void Rey::mover(Tablero* tablero, int posx, int posy, int cvx, int cvy) {

	if (color_pieza == BLANCO) {

		tablero->asignar(posx, posy, new Rey(BLANCO));

		if (posx != cvy || posy != cvx) {

			tablero->contador++;


		}
	}

	else if (color_pieza == NEGRO) {

		tablero->asignar(posx, posy, new Rey(NEGRO));
		if (posx != cvy || posy != cvx) {

			tablero->contador++;


		}
	}


	if (posx != cvy || posy != cvx) {

		tablero->asignar(cvy, cvx, new CasillaVacia(BLANCO));


	}



}