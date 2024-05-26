#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Peon : public Pieza
{
	bool comido;
	
	public:
		Sprite* sprite;
	Peon() = default;
	Peon( Vector2D coord, char eq, bool com,Sprite* spr) : Pieza(coord, eq), comido(com),sprite(spr) {}
	void dibuja(Vector2D coordenadas,char equipo);
};

