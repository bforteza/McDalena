#pragma once
#include "Tablero.h"
#include "iostream"
#include "ETSIDI.h"
#include "PantallaInicio.h"
#include "MenuMusica.h"
class Menu
{
	int estado=0;
	int muteado = 0;
	Tablero tablero1{ D, 5 };
	Tablero tablero2{ D, 5 };
	PantallaInicio pantallainicio;
	MenuMusica menumusica;
public:
	void dibuja();
	void detecta(int x, int y);
	void clica(int x, int y);

	friend PantallaInicio;
};

