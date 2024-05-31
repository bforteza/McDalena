#pragma once
#include <vector>
#include "Coordenadas.h"
#include <iostream>

class Tablero;

using std::vector;

enum Columna { A = 1, B, C, D, E, F, G };
enum Color { BLANCO = 0, NEGRO = 1 };
Color operator !(Color color);



class Pieza
{
protected:
	Color c_pieza{};
public:
	//metodos otención de datos
	virtual Color get_c_pieza() { return c_pieza; };
	
	virtual void print() {};

	virtual vector<Coordenadas*> premove(Tablero& tablero, Coordenadas posicion) {
		vector<Coordenadas*> res;
		return res;
	};
	//inicializador
	Pieza(Color pieza) : c_pieza(pieza) {};
};

