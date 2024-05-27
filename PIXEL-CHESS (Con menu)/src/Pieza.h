#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
#include "Casilla.h"
class Pieza: public Casilla//La pieza hereda de casilla
{
protected:
	Vector2D coordenadas;//Coordenadas para la pieza en la matriz
	Color color_pieza{};//Color de la pieza que viene heredado de casilla
public:
	
	//Constructores
	Pieza(Vector2D coord, Color c_pieza) : coordenadas(coord), color_pieza(c_pieza) {};
	Pieza();
	//Función para construir las piezas
	void print() {}; //Ponemos llaves para poder usar objetos

	friend class Tablero;//hacemos que el tablero tenga acceso a las piezas
};

