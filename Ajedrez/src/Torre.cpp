#include "Torre.h"
#include "Tablero.h"
#include <iostream>

void Torre::print() {

	std::cout << ((color_pieza == NEGRO) ? "K" : "k");
}

bool Torre::premove(Tablero* tablero, Columna col, int fil) {
	for (size_t i = 0; i <= tablero->cuadricula[col].size(); i++)
	{
		if (!tablero->get_casilla(static_cast<Columna>(i), fil)->ocupado())
		{
			tablero->get_casilla(static_cast<Columna>(i), fil)->selecionada = true;
		}
	}
	for (size_t i = 0; i <= tablero->cuadricula.size(); i++)
	{
		if (!tablero->get_casilla(static_cast<Columna>(i), fil + i)->ocupado())
		{
			tablero->get_casilla(static_cast<Columna>(i), fil+i)->selecionada = true;
		}
	}
	return true;
}