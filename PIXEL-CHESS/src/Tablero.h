#pragma once
#include "ETSIDI.h"
#include "Casilla.h"
#include <vector>
#include <iomanip>
#include <array>
#include <Pieza.h>
#include <Peon.h>
#include <Torre.h>
#include <Caballo.h>
#include<Alfil.h>
#include<Rey.h>
class Tablero
{
	std::vector<std::array<Casilla, 4>> casillas;
	
public:
	Peon Peon1_Negro = { {1,2},{'n'},{false},new Sprite("imagenes/PeonN.png", -1.66, 1.42, 0.74, 0.74) };
	Peon Peon1_Blanco = { {4,4},{'b'},{false},new Sprite("imagenes/PeonB.png", 1.58, -0.74, 0.94, 0.94) };
	Torre Torre1_Negro = { {4,1},{'n'},{false},new Sprite("imagenes/TorreN.png", -1.72, 1.36, 0.8, 0.8) };
	Torre Torre1_Blanco = { {1,5},{'b'},{false},new Sprite("imagenes/TorreB.png", 1.58, -0.74, 0.8, 0.8) };
	Caballo Caballo1_Negro = { {2,1},{'n'},{false},new Sprite("imagenes/CaballoN.png", -1.66, 1.40, 0.8, 0.8) };
	Caballo Caballo1_Blanco = { {3,5},{'b'},{false},new Sprite("imagenes/caballoB.png", 1.58, -0.74, 0.8, 0.8) };
	Alfil Alfil1_Negro = { {3,1},{'n'},{false},new Sprite("imagenes/AlfilN.png", -1.69, 1.43, 0.8, 0.8) };
	Alfil Alfil1_Blanco = { {2,5},{'b'},{false},new Sprite("imagenes/AlfilB.png", 1.58, -0.74, 0.8, 0.8) };
	Rey Rey1_Negro = { {1,1},{'n'},{false},new Sprite("imagenes/ReyN.png", -1.64, 1.43, 0.8, 0.8) };
	Rey Rey1_Blanco = { {4,5},{'b'},{false},new Sprite("imagenes/ReyB.png", 1.54, -0.74, 0.8, 0.8) };
	void inicializa();
	void dibuja();
};

