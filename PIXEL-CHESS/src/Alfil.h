#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Alfil : public Pieza
{
	bool comido;
	Sprite* sprite;
public:
	Alfil() = default;
	Alfil(Vector2D coord, char eq, bool com, Sprite* spr) : Pieza(coord, eq), comido(com), sprite(spr) {}
	void dibuja(Vector2D coordenadas, char equipo);
};
