#include "Peon.h"
#include "Tablero.h"
#include <iostream>

void Peon::print() {

	std::cout << ((color_pieza == NEGRO) ? "P" : "p");
}

std::vector <Casilla*> Peon::premueve(Tablero* tablero, Columna col, int fil) {

	Casilla* diag_1 = tablero->get_casilla(static_cast<Columna>(col - 1), fil - 1);
	Casilla* frente = tablero->get_casilla(static_cast<Columna>(col), fil - 1);
	Casilla* diag_2 = tablero->get_casilla(static_cast<Columna>(col + 1), fil - 1);

	if (movimientos == 0) { //Primer movimiento
		for (size_t i = 1; i <= 2; i++)
		{
			PosiblesMovimientos.push_back(tablero->get_casilla(static_cast<Columna>(col), fil + i));
		}
	} else {
		for (size_t i = 0; i <= tablero->cuadricula[col].size(); i++)
		{
			if (tablero->get_casilla(static_cast<Columna>(i), fil - 1) == diag_1 || diag_2 || frente && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
			{
				PosiblesMovimientos.push_back(tablero->get_casilla(static_cast<Columna>(i), fil - 1));
			}
		}
	}
}

