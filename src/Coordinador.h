#pragma once

#include "VentanaTablero.h"

class Coordinador
{
		char cancion1[30] = "bin/sonidos/Butterflies.mp3";
		char cancion2[30] = "bin/sonidos/LeapOfFaith.mp3";
		char cancion3[30] = "bin/sonidos/LiveFreeOrDie.mp3";
		bool muteado = false;
		
public:
	GLdouble ancho = 700, alto=700;
	VentanaTablero speedchess{ ancho,alto,"bin/imagenes/fondo.png",SC};
	VentanaTablero unicopeon{ ancho,alto,"bin/imagenes/fondo.png",UP };

	Ventana Menu{ ancho, alto,"bin/imagenes/Fondo2.png" };
	Ventana Integrantes{ ancho, alto,"bin/imagenes/FondoIntegrantes.png" };
	Ventana MenuMusica{ ancho, alto,"bin/imagenes/fondomusica.png" };

	Ventana* actual;
	void dibuja();
	void detecta(GLdouble x, GLdouble y);
	void click();

	void set_speedchess();
	void set_unicopeon();
	void set_menu();
	void set_menumusica();
	void set_salir();
	void set_butterflies();
	void set_leapoffaith();
	void set_livefreeordie();
	void set_mute();
	void set_unmute();
	void set_integrantes();
	Coordinador(GLdouble _ancho, GLdouble _alto);
};

