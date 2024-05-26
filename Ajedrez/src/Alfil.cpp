#include "Alfil.h"

#include "Tablero.h"

void Alfil::print() {

	std::cout << ((color_pieza == NEGRO) ? "B" : "b");
}

bool Alfil::premove(Tablero* tablero, Columna columna, int fila) {
	Columna col = columna;
	int fil = fila;
	while (tablero->get_casilla(static_cast<Columna>(col + 1), fil + 1) != nullptr && !tablero->get_casilla(static_cast<Columna>(col + 1), fil + 1)->ocupado()) {
		tablero->get_casilla(static_cast<Columna>(col + 1), fil + 1)->selecionada = true;
		col = static_cast<Columna>(col + 1);
		fil += 1;
	}
	return true;
}