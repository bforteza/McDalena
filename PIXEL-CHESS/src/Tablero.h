#pragma once
#include "ETSIDI.h"
#include "Casilla.h"
#include <vector>
#include <iomanip>
#include <array>
#include <Pieza.h>
#include <Peon.h>

class Tablero
{
	std::vector<std::array<Casilla, 4>> casillas;
	
public:
	Peon Peon1_Negro = { {1,2},{'n'},{false},new Sprite("imagenes/PeonN.png", -1.66, 1.42, 0.74, 0.74) };
	Peon Peon1_Blanco = { {4,4},{'b'},{false},new Sprite("imagenes/PeonB.png", 1.58, -0.74, 0.94, 0.94) };
	void inicializa();
	void dibuja();
};

