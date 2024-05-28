#pragma once
#include <iostream>

class Tablero;

enum Columna { A = 0, B, C, D, E, F, G };



enum Color {BLANCO=0, NEGRO=1};

Color operator !(Color color); 

class Casilla
{
protected:
	Color color_casilla{};
	
public:
	bool selecionada = 0;

	//virtual Color get_color_pieza() = 0;
	Color get_color_casilla();
	void set_color_casilla(Color color);

	virtual void print() = 0;
	virtual bool premove(Tablero* tablero, int col, int fil) = 0;
	virtual bool ocupado() = 0;
	virtual Casilla* puntero() = 0;

	void operator = (Casilla* entrada);

	//inicilizadores

	Casilla(Color ccasilla) : color_casilla(ccasilla) {};
	 

};

bool operator << (Casilla& base, Casilla& copida);