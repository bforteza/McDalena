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
	Color color{};
public:
	//metodos otención de datos
	virtual Color get_color() { return color; };
	
	virtual void print() {};

	virtual VectorCoordenadas premove(const Tablero* const tablero, const Coordenadas& posicion) {
		VectorCoordenadas res;
		return res;
	};

	VectorCoordenadas premove_dir(Coordenadas (&dir)[4], const Tablero* const tablero, const Coordenadas& posicion);
	
	
	//inicializador
	Pieza(Color pieza) : color(pieza) {};
};

