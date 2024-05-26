#pragma once
#include <vector>
#include "Casilla.h"

enum Columna{A=0,B,C,D,E,F,G};
enum Juego{SC,UP };
class Tablero
{
private:
	std::vector<std::vector< Casilla *>> cuadricula;

public:
	
	Casilla* get_casilla(Columna col, int fil);

	void size(Columna columnas, int filas);
	void print();
	void asignar(Columna col, int fil, Casilla* entrada);
	//inicializadores

	Tablero(Juego juego);
	
};

