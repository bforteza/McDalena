#pragma once

#include "VentanaTablero.h"

class Coordinador
{
public:
	GLdouble ancho = 700, alto=700;
	VentanaTablero speedchess{ ancho,alto,"bin/imagenes/fondo.png",SC};
	VentanaTablero unicopeon{ ancho,alto,"bin/imagenes/fondo.png",UP };

	Ventana Menu{ ancho, alto,"bin/imagenes/Fondo2.png" };

	Ventana* actual;

	void dibuja();
	void detecta(GLdouble x, GLdouble y);
	void click();

	void set_speedchess();
	void set_unicopeon();
	void set_menu();

	Coordinador(GLdouble _ancho, GLdouble _alto);
};

