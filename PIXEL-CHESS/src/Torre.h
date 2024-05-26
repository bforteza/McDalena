#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Torre : public Pieza//Torre hereda p�blicamente de pieza
{
	bool comido;//Estado para saber si se la han comido
	Sprite* sprite;//Sprite correspondiente
public:
	//Constructores
	Torre() = default;
	Torre(Vector2D coord, Color color_torre, bool com, Sprite* spr) : Pieza(coord, color_torre), comido(com), sprite(spr) {}
	//Funci�n para dibujar las torres
	void dibuja(Vector2D coordenadas, Color equipo);
};