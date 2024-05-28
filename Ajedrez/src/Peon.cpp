#include "Peon.h"
#include "Tablero.h"
#include <iostream>

void Peon::print() {

	std::cout << ((color_pieza == NEGRO) ? "P" : "p");
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