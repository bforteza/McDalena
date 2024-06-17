// Ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Tablero.h"
#pragma once






int main(int argc, char* argv[])
{
	int col;
	int fil;
	bool play = 1;
	Tablero prueba(UP);
	prueba.print();
	while (play) {
		std::cin >> col >> fil;
		prueba.entrada(Coordenadas(col, fil));
		prueba.print();
	}
}