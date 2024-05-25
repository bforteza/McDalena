#pragma once
#include <vector>
#include "Casilla.h"

enum Columna{A=0,B,C,D,E,F,G};
class Tablero
{
private:
	std::vector<std::vector< Casilla *>> cuadricula;

public:
	
	//Casilla& casilla(Columna col, int fil);

	void print();

	Tablero(Columna columnas, int filas);


};

