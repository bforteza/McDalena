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
	
public:
	std::vector<std::array<Casilla, 4>> casillas;
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

	Casilla Casilla11 = { {1,2},1,new Sprite("imagenes/cuadrado.png", -1.66, 2.50, 1.2, 1.2) };
	Casilla Casilla12 = { {1,2},1 , new Sprite("imagenes/cuadrado2.png", -0.58, 2.50, 1.2, 1.2) };
	Casilla Casilla13 = { {1,3},1,new Sprite("imagenes/cuadrado.png", 0.5, 2.50, 1.2, 1.2) };
	Casilla Casilla14 = { {1,4},1, new Sprite("imagenes/cuadrado2.png", 1.58, 2.50, 1.2, 1.2) };

	Casilla Casilla21 = { {2,1 }, 1, new Sprite("imagenes/cuadrado2.png", -1.66, 1.42, 1.2, 1.2) };
	Casilla Casilla22 = { {2,1},1,new Sprite("imagenes/cuadrado.png", -0.58, 1.42, 1.2, 1.2) };
	Casilla Casilla23 = { {2,2},1,new Sprite("imagenes/cuadrado2.png", 0.5, 1.42, 1.2, 1.2) };
	Casilla Casilla24 = { {2,4},1,new Sprite("imagenes/cuadrado.png", 1.58, 1.42, 1.2, 1.2) };

	Casilla Casilla31 = { {3,1 }, 1,  new Sprite("imagenes/cuadrado2.png", -1.66, -0.74, 1.2, 1.2) };
	Casilla Casilla32 = { {3,1 }, 1, new Sprite("imagenes/cuadrado.png", -0.58, -0.74, 1.2, 1.2) };
	Casilla Casilla33 = { {3,1 }, 1, new Sprite("imagenes/cuadrado2.png", 0.5, -0.74, 1.2, 1.2) };
	Casilla Casilla34 = { {3,1 }, 1, new Sprite("imagenes/cuadrado.png", 1.58, -0.74, 1.2, 1.2) };

	Casilla Casilla41 = { {4,1 }, 1,  new Sprite("imagenes/cuadrado.png", -1.66, 0.34, 1.2, 1.2) };
	Casilla Casilla42 = { {4,1 }, 1,  new Sprite("imagenes/cuadrado2.png", -0.58, 0.34, 1.2, 1.2) };
	Casilla Casilla43 = { {4,1 }, 1,  new Sprite("imagenes/cuadrado.png", 0.5, 0.34, 1.2, 1.2) };
	Casilla Casilla44 = { {4,1 }, 1,  new Sprite("imagenes/cuadrado2.png", 1.58, 0.34, 1.2, 1.2) };

	Casilla Casilla51 = { {5,1 }, 1,  new Sprite("imagenes/cuadrado.png", -1.66, -1.82, 1.2, 1.2) };
	Casilla Casilla52 = { {5,1 }, 1,  new Sprite("imagenes/cuadrado2.png", -0.58,  -1.82, 1.2, 1.2) };
	Casilla Casilla53 = { {5,1 }, 1,  new Sprite("imagenes/cuadrado.png", 0.5, -1.82, 1.2, 1.2) };
	Casilla Casilla54 = { {5,1 }, 1,  new Sprite("imagenes/cuadrado2.png", 1.58, -1.82, 1.2, 1.2) };
public:
	
	void inicializa();
	void dibuja();
};

