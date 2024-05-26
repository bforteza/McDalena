#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Casilla
{
	int estado;
	Vector2D coordenadas;

public:
	Sprite* sprite;
	Casilla(Vector2D coord,int est, Sprite *spr) : coordenadas(coord),estado(est), sprite(spr) {}
	void dibuja();
};

