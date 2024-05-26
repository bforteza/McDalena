#include "Rey.h"
#include "Tablero.h"
#include <iostream>

void Rey::print() {

	std::cout << ((color_pieza == NEGRO) ? "K" : "k");
}

bool Rey::premueve(Tablero* tablero, Columna col, int fil) {

	//Defino las posibles posiciones a las que se puede mover dada una posición incial:
	Casilla* diag_1 = tablero->get_casilla(static_cast<Columna>(col - 1), fil - 1);
	Casilla* frente = tablero->get_casilla(static_cast<Columna>(col), fil - 1);
	Casilla* diag_2 = tablero->get_casilla(static_cast<Columna>(col + 1), fil - 1);
	Casilla* diag_3 = tablero->get_casilla(static_cast<Columna>(col - 1), fil + 1);
	Casilla* atras = tablero->get_casilla(static_cast<Columna>(col), fil + 1);
	Casilla* diag_4 = tablero->get_casilla(static_cast<Columna>(col + 1), fil + 1);
	Casilla* izq = tablero->get_casilla(static_cast<Columna>(col - 1), fil);
	Casilla* dcha = tablero->get_casilla(static_cast<Columna>(col + 1), fil);

	//Con el bucle recorro la fila trasera, la de la pieza y la delantera, buscando que las posibles posiciones estén vacias
	for (size_t i = 0; i <= tablero->cuadricula[col].size(); i++)
	{
		if (tablero->get_casilla(static_cast<Columna>(i), fil - 1) == diag_1 && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			diag_1->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil - 1) == diag_2 && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			diag_2->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil - 1) == frente && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			frente->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil + 1) == diag_3 && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			diag_3->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil + 1) == atras && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			atras->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil + 1) == diag_4 && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			diag_4->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil) == izq && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			izq->selecionada = true;
		}
		else if (tablero->get_casilla(static_cast<Columna>(i), fil) == dcha && !tablero->get_casilla(static_cast<Columna>(i), fil - 1)->ocupado())
		{
			dcha->selecionada = true;
		}
	}
	return true;
}