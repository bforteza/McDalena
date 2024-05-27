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
enum Columna { A = 0, B, C, D, E, F, G };
//Columna que corresponde a una coordenada x
class Tablero
{
	//Matriz de casillas que conforman el tablero
	std::vector<std::vector< Casilla*>> cuadricula;
	Sprite volver = { "imagenes/PreVolver.png", -3,3,1, 1 };
	//Peones blanco y negro inicializados
	Torre Torre1_Negro = { { 3,0 }, NEGRO, 0, new Sprite("imagenes/TorreN.png", -0.66, 0.44, 0.8, 0.8) };
	Torre Torre1_Blanco = { {0,4},BLANCO,0,new Sprite("imagenes/TorreB.png", 2.58, -1.74, 0.8, 0.8) };

	//Caballos blanco y negro inicializados
	Caballo Caballo1_Negro = { {1,0},NEGRO,0,new Sprite("imagenes/CaballoN.png", -0.64, 0.44, 0.8, 0.8) };
	Caballo Caballo1_Blanco = { {2,4},BLANCO,0,new Sprite("imagenes/caballoB.png", 2.62, -1.72, 0.8, 0.8) };

	//Alfiles blanco y negro inicializados
	Alfil Alfil1_Negro = { {2,0},NEGRO,0,new Sprite("imagenes/AlfilN.png", -0.66, 0.44, 0.8, 0.8) };
	Alfil Alfil1_Blanco = { {1,4},BLANCO,0,new Sprite("imagenes/AlfilB.png", 2.58, -1.72, 0.8, 0.8) };

	//Reyes blanco y negro inicializados
	Rey Rey1_Negro = { {0,0},NEGRO,0,new Sprite("imagenes/ReyN.png", -0.66, 0.42, 0.8, 0.8) };
	Rey Rey1_Blanco = { {3,4},BLANCO,0,new Sprite("imagenes/ReyB.png", 2.62, -1.74, 0.8, 0.8) };

	//Peones blanco y negro inicializados
	Peon Peon1_Negro = { {0,1},NEGRO,0,new Sprite("imagenes/PeonN.png", -0.64, 0.42, 0.74, 0.74) };
	Peon Peon1_Blanco = { {3,3},BLANCO,0,new Sprite("imagenes/PeonB.png", 2.62, -1.74, 0.84, 0.84) };
public:

	//Constructores
	Tablero(Columna columnas, int filas);
	Tablero() = default;

	//Método de inicialización de casilla
	Casilla& casilla(Columna col, int fil);
	void dibujafondo();
	void print();
	void detectar(int x, int y);
	void clicar(int x, int y, int &estado);
};
