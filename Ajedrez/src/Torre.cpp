#include "Torre.h"
#include <iostream>

void Torre::print() {

	std::cout << ((color_pieza == NEGRO) ? "K" : "k");
}

std::vector <Casilla*> Torre::premueve(Tablero* tablero, Columna col, int fil) {
	for (size_t i = 0; i <= tablero->cuadricula[col].size(); i++)
	{
		if (!tablero->get_casilla(static_cast<Columna>(i), fil)->ocupado())
		{
			PosiblesMovimientos.push_back(tablero->get_casilla(static_cast<Columna>(i), fil + 1));
		}
	}
	for (size_t i = 0; i <= tablero->cuadricula.size(); i++)
	{
		if (!tablero->get_casilla(static_cast<Columna>(i), fil+i)->ocupado())
		{
			PosiblesMovimientos.push_back(tablero->get_casilla(static_cast<Columna>(col), i));
		}
	}
}