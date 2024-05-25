#include "Tablero.h"
#include "CasillaVacia.h"
#include <iostream>

//Casilla& Tablero::casilla(Columna col, int fil) {

	//return cuadricula[col][fil];
	
//}

Tablero::Tablero(Columna columnas, int filas) {

	cuadricula.resize(filas);
	for (size_t i = 0; i < cuadricula.size(); i++) {
		cuadricula[i].resize(columnas+1); // Cambiar el número de columnas en cada fila
	}

	Color color = NEGRO;
	for (auto& fila : cuadricula) {
		for (auto& casilla : fila) {
			casilla = new CasillaVacia(color);
			color = (color == NEGRO) ? BLANCO : NEGRO;
		}
	}

}

void Tablero::print() {
	for (auto fila : cuadricula) {
		for (auto casilla : fila) {
			casilla->print();
		}
		std::cout << "\n";
	}
}