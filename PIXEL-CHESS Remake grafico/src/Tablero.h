#pragma once
#include "Pieza.h"
#include "Peon.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Torre.h"
#include "Caballo.h"
#include "CasillaVacia.h"
#include "ETSIDI.h"
#include "freeglut.h"

enum Juego { UP, SC };
class Tablero
{
private:
	vector<Pieza*> cuadricula;
	Sprite volver = { "imagenes/PreVolver.png", -3,3,1, 1 };
	Coordenadas tam;				//tamaño
	vector<Pieza*> muertas;

	VectorCoordenadas seleccion, p_blancas, p_negras;

	void asignar(Coordenadas e, Pieza* entrada);
	void buscar_piezas();
	double origenx, origeny;
	int spriteorigenx, spriteorigeny;


public:
	std::vector<std::vector< CasillaVacia*>> base;
	bool fmove(const Coordenadas& origen, const Coordenadas& destino);
	//parametros
	Coordenadas get_tam() { return tam; };
	Pieza*& get_pieza(Coordenadas entrada);
	Coordenadas rey(Color color);

	void size(int columnas, int filas);
	void print();

	bool jaque(Color color);
	void seleccionar(const VectorCoordenadas&);
	void borrar_seleccion();

	void detectar(int x, int y, Juego juego);
	void clicar(int x, int y, int& estado, Juego juego, int& coordenadas_x, int& coordenadas_y);

	VectorCoordenadas premove(const Coordenadas& e);

	//inicializadores
	Tablero(Juego juego);
	Tablero(Juego juego, vector<Pieza*>& piezas);
};

