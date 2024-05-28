#pragma once
#include <vector>
#include "Casilla.h"
#include "CasillaVacia.h"
#include "Alfil.h"
#include "Rey.h"
#include "Torre.h"
#include "Caballo.h"
#include "Reina.h"
#include "Peon.h"
enum Juego{SC,UP };
class Tablero
{

	

public:
	std::vector<std::vector< Casilla*>> cuadricula;

	Rey* get_rey(Color color);
	Casilla* get_casilla(int col, int fil);

	void size(int columnas, int filas);
	void print();
	void asignar(int col, int fil, Casilla* entrada);

	bool premove(int col, int fil);
	void borrar_seleccion();
	
	bool jacke(Color color); //devuelve true si hay un jacke del colo indicado

	//inicializadores

	Tablero(Juego juego);
	
};

