#pragma once
#include <iostream>
#include "ETSIDI.h"
#include "freeglut.h"
using ETSIDI::Sprite;

class Tablero;

enum Columna { A = 0, B, C, D, E, F, G };



enum Color {BLANCO=0, NEGRO=1, VERDE=2, ROJO=3};

Color operator !(Color color); 

class Casilla
{
protected:

	Sprite* sprite_casilla; //Sprite Correspondiente
	Sprite* sprite_pieza; //Sprite Correspondiente
	Color color_casilla{};
	
public:
	bool selecionada = 0;

	//virtual Color get_color_pieza() = 0;
	Color get_color_casilla();
	void set_color_casilla(Color color);

	virtual void print(int col, int fil, double origenx, double origeny) = 0;
	virtual bool premove(Tablero* tablero, int col, int fil) = 0;
	virtual bool ocupado() = 0;
	virtual Casilla* puntero() = 0;

	void operator = (Casilla* entrada);

	//inicilizadores

	Casilla(Color ccasilla) : color_casilla(ccasilla) {};

	friend Tablero;
	 

};

bool operator << (Casilla& base, Casilla& copida);