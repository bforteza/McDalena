#pragma once
#include "Pieza.h"
using ETSIDI::Sprite;
class Alfil : public Pieza //Heredamos el alfil de pieza públicamente
{
	bool comido; //Para comprobar si la pieza se ha comido o no
	Sprite* sprite; //Sprite correspondiente
public:
	//Constructores
	Alfil() = default;
	Alfil(Vector2D coord,Color color_alfil , bool com, Sprite* spr) : Pieza(coord, color_alfil), comido(com), sprite(spr) {}
	//Método para dibujar las piezas
	void dibuja(Vector2D coordenadas, Color equipo);

	friend class Tablero;//hacemos que el tablero tenga acceso a las piezas
};
