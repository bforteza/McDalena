#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;
enum Color { BLANCO = 0, NEGRO = 1 };//Enumeración para identificar blanco y negro
class Casilla
{
	bool selecionada = 0;
protected:

	Vector2D coordenadas; //Coordenadas de la casilla en la matriz
	Color color_casilla{}; //Color corresboniente
	Sprite* sprite; //Sprite Correspondiente

public:
	
	//Constructores
	Casilla(Color ccasilla, Sprite *spr) : color_casilla(ccasilla),sprite(spr) {};
	Casilla() = default;

	//Función virtual pura para dibujar
	virtual void print() = 0;
};