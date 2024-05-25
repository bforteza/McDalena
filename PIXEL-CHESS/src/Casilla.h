#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Casilla
{
	Sprite *sprite;
public:

	Casilla(Sprite *spr) :sprite(spr) {}
	void dibuja();
};

