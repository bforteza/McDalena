#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Rey : public Pieza //Rey hereda de pieza p�blicamente
{
	bool jaque; //Estado de jaque
	Sprite* sprite; //Sprite correspondiente
public:
	//Constructores
	Rey() = default; 
	Rey(Vector2D coord, Color color_rey, bool com, Sprite* spr) : Pieza(coord, color_rey), jaque(com), sprite(spr) {}
	//Funci�n para dibujar las piezas
	void dibuja(Vector2D coordenadas, Color equipo);
};
