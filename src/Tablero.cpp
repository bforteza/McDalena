#include "Tablero.h"

Tablero::Tablero(Juego juego){
	if (juego == SC) {
		filas = 6;
		columnas = 6;
	}

	cuadricula.resize( filas * columnas );

	for (auto& iter : cuadricula) {
		iter = nullptr;
	}

	if (juego == SC) {
		for (int c = 1; c <= columnas; c++) {
			asignar({ c , 2 }, new Peon(BLANCO));
			asignar({ c , 5 }, new Peon(NEGRO));
		}
	}

	
}

Pieza*& Tablero::get_pieza(Coordenadas entrada) {
	
	if( entrada.col>0 && entrada.col <= columnas && 
		entrada.fil > 0 && entrada.fil <= filas)
	return cuadricula[entrada.col - 1 + (entrada.fil - 1) * (columnas)];

	Pieza* retorno = nullptr;
	return retorno;
} 

void Tablero::print() {
	for (int f = filas; f != 0; f--) {
		std::cout << f;
		for (int c = 1; c <= columnas; c++) {
			if (get_pieza({ c,f }) != nullptr)
				get_pieza({ c,f })->print();
			else
				std::cout << " ";
			std::cout << " ";
		}
		std::cout << "\n";
	}
	char letra = 'A';
	for (int c = 1; c <= columnas; c++) {
	
		std::cout << " " << letra;
		letra++;
	}
	
}

void Tablero::asignar(Coordenadas e, Pieza* entrada) {
	if (get_pieza(e) == nullptr) {
		get_pieza(e) = entrada;
	}
}