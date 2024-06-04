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
	//logica
	vector<Pieza*> cuadricula;
	//Sprite volver = { "bin/imagenes/PreVolver.png", -3,3,1, 1 };
	Coordenadas tam; //tamaño
	vector<Pieza*> muertas;
	VectorCoordenadas seleccion, p_blancas, p_negras;


	//GL gluut
	GLdouble origenx, origeny;
	GLdouble finalx, finaly;
	double lado = 100;

	void asignar(Coordenadas e, Pieza* entrada);
	void buscar_piezas();

	std::vector< CasillaVacia* > base;
	bool fmove(const Coordenadas& origen, const Coordenadas& destino);

	Coordenadas Piezaamover{0,0};
	Color turno = BLANCO;
public:

	//parametros

	Coordenadas get_tam() { return tam; };
	Pieza*& get_pieza(const Coordenadas entrada);
	Pieza* get_pieza(const Coordenadas entrada) const;
	CasillaVacia*& get_CasillaVacia(const Coordenadas entrada);
	Coordenadas rey(const Color color);


	void dibuja();

	bool jaque(Color color);
	void seleccionar(const VectorCoordenadas&);
	void borrar_seleccion();

	void detectar(int x, int y);
	void clicar(int x, int y);

	VectorCoordenadas premove(const Coordenadas& e);
	void move(const Coordenadas& e);

	//inicializadores
	Tablero(Juego juego);
};

