#include "Reina.h"
#include <iostream>

void Reina::print() {

	std::cout << ((color_pieza == NEGRO) ? "Q" : "q");
}

bool Reina::premove(Rey rey, Alfil al, Tablero* tablero, Columna col, int fil) {
	rey.premove(tablero, col, fil);
	al.premove(tablero, col, fil);
	//La reina puede moverse como el alfil y el rey, pues llamo a las funciones premove de ambos y que se ejecuten
	return true;
}