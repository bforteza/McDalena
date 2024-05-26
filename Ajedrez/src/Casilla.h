#pragma once
#include <iostream>

enum Color {BLANCO=0, NEGRO=1};
class Casilla
{
protected:
	Color color_casilla{};
public:
	virtual void print() = 0;
	Casilla(Color ccasilla) : color_casilla(ccasilla) {};
	Color get_color_casilla();
	void set_color_casilla(Color color);
	//virtual void dibuja();
};

