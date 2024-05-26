#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
class Pieza
{
protected:
	Vector2D coordenadas;
	char equipo;

public:

	Pieza(Vector2D coord, char eq) : coordenadas(coord), equipo(eq) {};

	friend class Tablero;
};

