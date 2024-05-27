#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Caballo : public Pieza //Heredamos el alfil públicamente de la pieza
{
	bool comido;//Bool para comprobar si se ha comido la pieza
	Sprite* sprite;// Sprite correspondiente
public:
	//Constructores
	Caballo() = default;
	Caballo(Vector2D coord, Color color_caballo, bool com, Sprite* spr) : Pieza(coord, color_caballo), comido(com), sprite(spr) {}
	//Método para dibujar las piezas
	void dibuja(Vector2D coordenadas, Color equipo);

	friend class Tablero;//hacemos que el tablero tenga acceso a las piezas
};