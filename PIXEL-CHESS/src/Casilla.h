#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;
enum Color { BLANCO = 0, NEGRO = 1 };//Enumeraci�n para identificar blanco y negro
class Casilla
{
protected:
	int estado;// Estado para comprobar si la casilla est� ocupada y c�mo est� ocupada
	Vector2D coordenadas; //Coordenadas de la casilla en la matriz
	Color color_casilla{}; //Color corresboniente
	Sprite* sprite; //Sprite Correspondiente

public:
	
	//Constructores
	Casilla(Color ccasilla, Sprite *spr, Vector2D coord) : color_casilla(ccasilla),sprite(spr) {};
	Casilla() = default;

	//Funci�n virtual pura para dibujar
	virtual void print() = 0;
};