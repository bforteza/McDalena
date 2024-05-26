#pragma once
#include <vector>
#include "Casilla.h"
#include "CasillaVacia.h"
#include "Alfil.h"


enum Juego{SC,UP };
class Tablero
{

	

public:
	std::vector<std::vector< Casilla*>> cuadricula;

	Casilla* get_casilla(Columna col, int fil);

	void size(Columna columnas, int filas);
	void print();
	void asignar(Columna col, int fil, Casilla* entrada);
	bool premove(Columna col, int fil);
	
	//inicializadores

	Tablero(Juego juego);
	
};

