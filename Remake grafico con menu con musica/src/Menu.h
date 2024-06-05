#pragma once
#include "Tablero.h"
#include "iostream"
#include "ETSIDI.h"
#include "Ventana.h"
#include "VentanaTablero.h"
class Menu
{
	int estado=0;
	int muteado = 1;
	int marcamusica;
	int coordenadax = 0, coordenaday = 0;
	Ventana PantallaInicio{800,800,"bin/imagenes/Fondo2.png" };
	Ventana MenuMusica{ 800,800,"bin/imagenes/fondomusica.png" };
	VentanaTablero UnPeon{ 800,800,"bin/imagenes/Fondo.png",UP };
	VentanaTablero SpeedChess{ 800,800,"bin/imagenes/Fondo.png",SC };
public:
	Tablero tablero1{ SC };
	Tablero tablero2{ UP };

	void set();
	void dibuja();
	void detecta(int x, int y);
	void clica(int x, int y);

};

