#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Rey : public Pieza
{
	bool comido;
	Sprite* sprite;
public:
	Rey() = default;
	Rey(Vector2D coord, char eq, bool com, Sprite* spr) : Pieza(coord, eq), comido(com), sprite(spr) {}
	void dibuja(Vector2D coordenadas, char equipo);
};
