#include "Tablero.h"
#include "CasillaVacia.h"
#include <iostream>
#include "Peon.h"
#include "Torre.h"
#include "Rey.h"
#include "Reina.h"
#include "Alfil.h"

void Tablero::size(Columna columnas, int filas) {

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
		color = (color == NEGRO) ? BLANCO : NEGRO;
	}

}

Tablero::Tablero(Juego juego) {
	if (juego == UP) {
		size(D, 5);
		asignar(A, 1, new Rey(BLANCO)); //falta implementar todas las demas piezas
	}
	else if (juego == SC) {

		size(E, 6); //falta implementar todas las piezas

	}
}

void Tablero::print() {
	for (auto fila : cuadricula) {
		for (auto casilla : fila) {
			casilla->print();
		}
		std::cout << "\n";
	}
} //falta mejorar el metodo print para que las casillas aparezcan en su lugar

Casilla* Tablero::get_casilla(Columna col, int fil) {
	return cuadricula[col][fil];
}

void Tablero::asignar(Columna col, int fil, Casilla* entrada) {

	
	entrada->set_color_casilla(cuadricula[col][fil-1]->get_color_casilla());

	delete cuadricula[col][fil-1];
	cuadricula[col][fil-1] = entrada;
}

