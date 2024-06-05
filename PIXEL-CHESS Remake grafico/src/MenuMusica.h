#pragma once
#include "ETSIDI.h"
using ETSIDI::Sprite;
class MenuMusica
{
	Sprite papel = { "bin/imagenes/menumusica.png", 0, 0.0,6, 7 };
	Sprite titulomusica = { "bin/imagenes/musica2.png", 0.05,0.5,6, 6 };
	Sprite mute = { "bin/imagenes/NoMute.png", 3,3,1, 1 };
	Sprite volver = { "bin/imagenes/PreVolver.png", -3,3,1, 1 };
	int Color_LeapOfFaith[3]{ 0,0,0 };
	int T_LeapOfFaith = 48;
	int Color_LiveFreeOrDie[3]{ 0,0,0 };
	int T_LiveFreeOrDie = 48;
	int Color_Butterflies[3]{ 0,0,0 };
	int T_Butterflies = 48;
public:
	void dibuja();
	void clicar(int x, int y, int& estado,int &muteado);
	void detectar(int x, int y);
};