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
	std::vector<Casilla*> movimientos{};

public:
	std::vector<std::vector< Casilla*>> cuadricula;

	Rey* get_rey(Color color);
	Casilla*& get_casilla(int col, int fil);

	void size(int columnas, int filas);
	void print();
	void asignar(int col, int fil, Casilla* entrada);
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

