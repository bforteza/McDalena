#pragma once
#include <iostream>

class Tablero;

enum Columna { A = 0, B, C, D, E, F, G };
enum Color {BLANCO=0, NEGRO=1};
class Casilla
{
protected:
	Color color_casilla{};
	
public:
	bool selecionada = 0;

	
	Color get_color_casilla();
	void set_color_casilla(Color color);

	virtual void print() = 0;
	virtual bool premove(Tablero* tablero, Columna col, int fil) = 0;
	virtual bool ocupado() = 0;
	//inicilizadores

	Casilla(Color ccasilla) : color_casilla(ccasilla) {};


};

