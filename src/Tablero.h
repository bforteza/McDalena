#pragma once
#include "Pieza.h"
#include "Peon.h"

enum Juego{UP,SC};
class Tablero
{
private:
	vector<Pieza*> cuadricula;
	int filas = 1;
	int columnas = 1;


	void asignar(Coordenadas e, Pieza* entrada);
public:


	Pieza*& get_pieza(Coordenadas entrada);
	void print();



	//inicializadores
	Tablero(Juego juego);
};

