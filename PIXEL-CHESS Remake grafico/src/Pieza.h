#pragma once
#include <vector>
#include "Coordenadas.h"
#include <iostream>
#include "ETSIDI.h"

class Tablero;

using std::vector;
using ETSIDI::Sprite;

enum Columna { A = 1, B, C, D, E, F, G };
enum Color { BLANCO = 0, NEGRO = 1,VERDE =2, ROJO =3 };
Color operator !(Color color);



class Pieza
{
protected:
	Color color{}; 
	Sprite* sprite_casilla; //Sprite Correspondiente
	Sprite* sprite_pieza; //Sprite Correspondiente
public:
	//metodos otención de datos
	virtual Color get_color() { return color; };

	virtual void print(int col, int fil, double origenx, double origeny) {};

	virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion) {
		VectorCoordenadas res;
		return res;
	};

	VectorCoordenadas premove_dir(Coordenadas(&dir)[4], Tablero* tablero, const Coordenadas& posicion);
	void set_color(Color color_asignado) {
		color = color_asignado;
	}

	//inicializador
	Pieza(Color pieza) : color(pieza) {};
};


