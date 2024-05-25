#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Caballo : public Pieza
{
	bool comido;
	Sprite* sprite;
public:
	Caballo() = default;
	Caballo(Vector2D coord, char eq, bool com, Sprite* spr) : Pieza(coord, eq), comido(com), sprite(spr) {}
	void dibuja(Vector2D coordenadas, char equipo);
};