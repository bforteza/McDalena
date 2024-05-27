#pragma once
#include "Tablero.h"
#include "iostream"
#include "ETSIDI.h"
#include "PantallaInicio.h"
#include "MenuMusica.h"
enum Modalidad { CUATROPORCINCO = 0, SPEEDCHESS = 1 };
class Menu
{
	int estado=0;
	int muteado = 1;
	Tablero tablero1{ D, 5 ,-1.66,2.50,212,60,CUATROPORCINCO };
	Tablero tablero2{ E, 6 ,-1.96,2.85,179,27,SPEEDCHESS };
	PantallaInicio pantallainicio;
	MenuMusica menumusica;
public:
	void dibuja();
	void detecta(int x, int y);
	void clica(int x, int y);

	friend PantallaInicio;
};

