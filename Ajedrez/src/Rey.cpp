#include "Rey.h"
#include <iostream>

void Rey::print() {

	std::cout << ((color_pieza == NEGRO) ? "K" : "k");
}

std::vector <Casilla*> Rey::premueve(Tablero* tablero, Columna col, int fil){
	Casilla* diag_1 = tablero->get_casilla(static_cast<Columna>(col - 1), fil - 1);
	Casilla* frente = tablero->get_casilla(static_cast<Columna>(col), fil - 1);
	Casilla* diag_2 = tablero->get_casilla(static_cast<Columna>(col + 1), fil - 1);
	Casilla* diag_3 = tablero->get_casilla(static_cast<Columna>(col - 1), fil + 1);
	Casilla* atras = tablero->get_casilla(static_cast<Columna>(col), fil + 1);
	Casilla* diag_4 = tablero->get_casilla(static_cast<Columna>(col + 1), fil + 1);
	Casilla* izq = tablero->get_casilla(static_cast<Columna>(col - 1), fil);
	Casilla* dcha = tablero->get_casilla(static_cast<Columna>(col + 1), fil);

	for (size_t i = 0; i <= tablero->cuadricula[col].size(); i++)
	{
		if (tablero->get_casilla(static_cast<Columna>(i), fil - 1) == diag_1 || diag_2 || frente && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			PosiblesMovimientos.push_back(tablero->get_casilla(static_cast<Columna>(i), fil - 1));
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil + 1) == diag_3 || diag_4 || atras && !tablero->get_casilla(static_cast<Columna>(i), fil + 1)->ocupado())
		{
			PosiblesMovimientos.push_back(tablero->get_casilla(static_cast<Columna>(i), fil + 1));
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil) == izq || dcha && !tablero->get_casilla(static_cast<Columna>(i), fil )->ocupado())
		{
			PosiblesMovimientos.push_back(tablero->get_casilla(static_cast<Columna>(i), fil + 1));
		}
	}
}