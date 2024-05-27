#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Peon : public Pieza //Heredamos el peon de manera pública de la clase pieza
{
	bool comido;//Estado para saber si se lo han comido o no
	Sprite* sprite;//Sprite correspondiente
	public:
		
	//Constructores
	Peon() = default;
	Peon( Vector2D coord, Color color_peon, bool com,Sprite* spr) : Pieza(coord, color_peon), comido(com),sprite(spr) {}
	//Función para dibujar los peones
	void dibuja(Vector2D coordenadas,Color equipo);
};

