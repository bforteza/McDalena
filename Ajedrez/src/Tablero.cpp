#include "Tablero.h"
#include <iostream>

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
		asignar(A, 1, new Alfil(BLANCO)); //falta implementar todas las demas piezas
	}
	else if (juego == SC) {

		size(E, 6); //falta implementar todas las piezas

	}
}

void Tablero::print() {
	for (auto fila : cuadricula) {
		for (auto casilla : fila) {
			casilla->print();
			if (casilla->selecionada == 1) {
				std::cout << ".";
			}
		}
		std::cout << "\n";
	}
} //falta mejorar el metodo print para que las casillas aparezcan en su lugar

Casilla* Tablero::get_casilla(Columna col, int fil) {
	if(col >= 0 && col < cuadricula.size() && (fil-1) >= 0 && (fil-1) < cuadricula[0].size())
	return cuadricula[col][fil-1];
	return nullptr;
}

void Tablero::asignar(Columna col, int fil, Casilla* entrada) {

	
	entrada->set_color_casilla(cuadricula[col][fil-1]->get_color_casilla());

	delete cuadricula[col][fil-1];
	cuadricula[col][fil-1] = entrada;
}

bool Tablero::premove(Columna col, int fil) {
	if (get_casilla(col, fil)->premove(this,col, fil)) return true;
	return false;
}

