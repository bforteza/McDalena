#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Reina : public Pieza//La reina hereda de Pieza
{
	bool comido;//Estado para saber si se la han comido
	Sprite* sprite;//Sprite correspondiente
public:
	//Constructores
	Reina() = default;
	Reina(Vector2D coord, Color color_alfil, bool com, Sprite* spr) : Pieza(coord, color_alfil), comido(com), sprite(spr) {}
	//Función para dibujarlas
	void dibuja(Vector2D coordenadas, Color equipo);
};