#include "Tablero.h"
#include <iostream>

void Tablero::size(int columnas, int filas) {

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
		asignar(A, 4, new Rey(BLANCO));
		asignar(C, 3, new Caballo(NEGRO));//falta implementar todas las demas piezas
		asignar(B, 1, new Torre(BLANCO));
		asignar(C, 1, new Caballo(BLANCO));
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
				std::cout << ". ";
			}
			else {
				std::cout << "  ";
			}
			
		}
		std::cout << "\n";
	}
} //falta mejorar el metodo print para que las casillas aparezcan en su lugar

Casilla* Tablero::get_casilla(int col, int fil) {

	if (fil-1 >= 0 && fil-1 < cuadricula.size() && col >= 0 && col < cuadricula[0].size())
		return cuadricula[fil-1][col];
	return nullptr;
}

void Tablero::asignar(int col, int fil, Casilla* entrada) {

	
	entrada->set_color_casilla(cuadricula[fil-1][col]->get_color_casilla());

	delete cuadricula[fil-1][col];
	cuadricula[fil-1][col] = entrada;
}

bool Tablero::premove(int col, int fil) {
	borrar_seleccion();
	if (get_casilla(col, fil)->premove(this,col, fil)) return true;
	return false;
}

void Tablero::borrar_seleccion() {
	for (auto& fila : cuadricula) {
		for (auto& casilla : fila) {
			casilla->selecionada = 0;
		}
	}
}