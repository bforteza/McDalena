#pragma once
#include "ETSIDI.h"

using ETSIDI::Sprite;
class PantallaInicio
{
	Sprite pixelchess = { "imagenes/pixelchess.png", 0.4,2.6,14, 9 };
	int Color_UnPeon[3]  { 0,0,0 };
	int Color_Speed[3]  { 0,0,0 };
	int Color_Musica[3]  { 0,0,0 };
	int Color_Salir[3]  { 0,0,0 };
	int T_UnPeon= 48;
	int T_Speed=48;
	int T_Musica=48;
	int T_Salir=48;
public:
	void dibuja();
	void clicar(int x, int y,int &estado);
	void detectar(int x, int y);

	friend class Menu;
};