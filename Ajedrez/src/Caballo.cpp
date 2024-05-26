#include <iostream>
#include "Caballo.h"
#include "Tablero.h"

void Caballo::print() {

	std::cout << ((color_pieza == NEGRO) ? "K" : "k");
}

bool Caballo::premove(Tablero* tablero, Columna col, int fil) {
	Casilla* L1 = tablero->get_casilla(static_cast<Columna>(col - 2), fil - 1);
	Casilla* L2 = tablero->get_casilla(static_cast<Columna>(col-  1), fil - 2);
	Casilla* L3 = tablero->get_casilla(static_cast<Columna>(col + 1), fil - 2);
	Casilla* L4 = tablero->get_casilla(static_cast<Columna>(col + 2), fil - 1);
	Casilla* L5 = tablero->get_casilla(static_cast<Columna>(col + 2), fil + 1);
	Casilla* L6 = tablero->get_casilla(static_cast<Columna>(col + 1), fil + 2);
	Casilla* L7 = tablero->get_casilla(static_cast<Columna>(col - 1), fil + 2);
	Casilla* L8 = tablero->get_casilla(static_cast<Columna>(col - 2), fil + 1);

	for (size_t i = 0; i <= tablero->cuadricula[col].size(); i++)
	{
		if (tablero->get_casilla(static_cast<Columna>(i), fil - 1) == L1 && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			L1->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil - 2) == L2 && !tablero->get_casilla(static_cast<Columna>(i), fil - 2)->ocupado())
		{
			L2->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil - 2) == L3 && !tablero->get_casilla(static_cast<Columna>(i), fil - 2)->ocupado())
		{
			L3->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil - 1) == L4 && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			L4->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil + 1) == L5 && !tablero->get_casilla(static_cast<Columna>(i), fil + 1)->ocupado())
		{
			L5->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil + 2) == L6 && !tablero->get_casilla(static_cast<Columna>(i), fil + 2)->ocupado())
		{
			L6->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil + 2) == L7 && !tablero->get_casilla(static_cast<Columna>(i), fil + 2)->ocupado())
		{
			L7->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil + 1) == L8 && !tablero->get_casilla(static_cast<Columna>(i), fil + 1)->ocupado())
		{
			L8->selecionada = true;
		}
	}
	return true;
}