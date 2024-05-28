#pragma once
#include <vector>
#include "Casilla.h"
#include "CasillaVacia.h"
#include "Alfil.h"
#include "Rey.h"
#include "Torre.h"
#include "Caballo.h"
#include "Reina.h"

enum Juego{SC,UP };
class Tablero
{

	

public:
	std::vector<std::vector< Casilla*>> cuadricula;


	Casilla* get_casilla(int col, int fil);

	void size(int columnas, int filas);
	void print();
	void asignar(int col, int fil, Casilla* entrada);

	bool premove(int col, int fil);
	void borrar_seleccion();
	
	//inicializadores

	Tablero(Juego juego);
	
};

