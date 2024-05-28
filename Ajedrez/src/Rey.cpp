#include "Rey.h"
#include "Tablero.h"
#include <iostream>
#include "Torre.h"
void Rey::print() {

	std::cout << ((color_pieza == NEGRO) ? "Kg" : "kg");
}

bool Rey::premove(Tablero* tablero, int col, int fil) {
	bool retorno = false;
	Casilla* aux;

	for (int auxcol = col - 1; auxcol <= col + 1; auxcol++) {
		for (int auxfil = fil - 1; auxfil <= fil + 1; auxfil++) { //recorre cuadricula 3x3

			aux = tablero->get_casilla(auxcol, auxfil);

			if (aux != nullptr && !aux->ocupado()) { 
				aux->selecionada = true;
				retorno = true;
			}
			else if (aux != nullptr && aux->ocupado() && dynamic_cast<Pieza*>(aux)->get_color_pieza() != color_pieza) {
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