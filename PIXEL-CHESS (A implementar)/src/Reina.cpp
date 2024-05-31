#include "Reina.h"
#include <iostream>

void Reina::print(int col, int fil, double origenx, double origeny) {

	std::cout << ((color_pieza == NEGRO) ? "Q" : "q");
}

bool Reina::premove( Tablero* tablero, int col, int fil) {
	bool retorno = false;
	retorno = Rey(color_pieza).premove(tablero, col, fil) ||
	Alfil(color_pieza).premove(tablero, col, fil) ||
	Torre(color_pieza).premove(tablero, col, fil);
	//La reina puede moverse como el alfil y el rey, pues llamo a las funciones premove de ambos y que se ejecuten
	return retorno;
}