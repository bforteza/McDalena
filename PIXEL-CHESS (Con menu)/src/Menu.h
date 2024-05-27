#pragma once
#include "Tablero.h"
#include "iostream"
#include "ETSIDI.h"
#include "PantallaInicio.h"
class Menu
{
	int estado=0;
	Tablero tablero1{ D, 5 };
	PantallaInicio pantallainicio;
public:
	void dibuja();
	void detecta(int x, int y);
	void clica(int x, int y);

	friend PantallaInicio;
};

