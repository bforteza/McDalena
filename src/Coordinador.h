#pragma once

#include "VentanaTablero.h"

class Coordinador
{
		char cancion1[30] = "sonidos/Butterflies.mp3";
		char cancion2[30] = "sonidos/LeapOfFaith.mp3";
		char cancion3[30] = "sonidos/LiveFreeOrDie.mp3";
		bool muteado = false;

public:
	GLdouble ancho = 700, alto=700;
	VentanaTablero speedchess{ ancho,alto,"imagenes/fondo.png",SC};
	VentanaTablero unicopeon{ ancho,alto,"imagenes/fondo.png",UP };

	Ventana Menu{ ancho, alto,"imagenes/Fondo2.png" };
	Ventana Integrantes{ ancho, alto,"imagenes/Tatooine.png" };
	Ventana MenuMusica{ ancho, alto,"imagenes/fondomusica.png" };

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
	void activa_vader() {}
	Coordinador(GLdouble _ancho, GLdouble _alto);
};

