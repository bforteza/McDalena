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
#include "coordenadas.h"
enum Juego{SC,UP };

class Tablero
{
	std::vector<Casilla*> movimientos{};
	double origenx, origeny;
	int spriteorigenx, spriteorigeny;
	Sprite volver = { "imagenes/PreVolver.png", -3,3,1, 1 };
	Coordenadas tam;				//tamaño

	VectorCoordenadas seleccion, p_blancas, p_negras;

	void asignar(Coordenadas e, Pieza* entrada);
	void buscar_piezas();
public:
	std::vector<std::vector< Casilla*>> cuadricula;

	Rey* get_rey(Color color);
	Casilla*& get_casilla(int col, int fil);

	void size(int columnas, int filas);
	void print();
	void asignar(int col, int fil, Casilla* entrada);
	void detectar(int x, int y,Juego juego);
	void clicar(int x, int y, int& estado,Juego juego,int &coordenadas_x,int &coordenadas_y);


	std::vector<Casilla*> get_mov() { return movimientos; }

	bool fmove(int Ocol, int Ofil, int Dcol, int Dfil);
	bool premove(int col, int fil);
	void borrar_seleccion();
	
	bool jaque(Color color); //devuelve true si hay un jacke del colo indicado
	bool mate(Color color);
	bool ahogado(Color color);

	
	//inicializadores

	Tablero(Juego juego);
	Tablero(Tablero& entrada);

	//destructor
	~Tablero() {
		for (auto& fila : cuadricula) {
			for (auto& casilla : fila) {
				delete casilla;
			}
		}
	}
};

