#pragma once
#include "Pieza.h"
#include "Peon.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Torre.h"
#include "Caballo.h"
#include "CasillaVacia.h"



enum Juego { UP, SC };
class Tablero
{
private:
	
	Juego juego;
	vector<Pieza*> cuadricula;
	Coordenadas tam; //tamaño
	vector<Pieza*> muertas;
	VectorCoordenadas p_blancas, p_negras;
	Color turno = BLANCO;

	
	
	Coordenadas PeonCoronacion;

	Coordenadas rey(const Color color);
	void borrar_seleccion();
	void asignar(Coordenadas e, Pieza* entrada);
	void buscar_piezas();
	bool fmove(const Coordenadas& origen, const Coordenadas& destino);
	void move(const Coordenadas& e);
	void seleccionar(const VectorCoordenadas&);
	
	VectorCoordenadas premove(const Coordenadas& e);
public:

	bool jaque(Color color);
	bool ahogado(Color color);
	bool mate(Color color);
	
	bool coronacion = false;
	VectorCoordenadas seleccion;
	Coordenadas Piezaamover{ 0,0 };

	
	Coordenadas get_tam() { return tam; };
	Pieza*& get_pieza(const Coordenadas entrada);
	Pieza* get_pieza(const Coordenadas entrada) const;
	vector<Pieza*>& get_cuadricula();
	
	void set_coronacion(char e);
	
	Color get_turno() { return turno; };

	void restart();
	void guarda();
	void lodea();

	Juego get_juego() { return juego; }


	void entrada(const Coordenadas& e);
	//inicializadores
	Tablero(Juego juego);
	Tablero(Juego juego, vector<Pieza*>& piezas);

	~Tablero() {
		for (auto& iter : cuadricula) {
			if (iter != nullptr)
				delete iter;
		}
		for (auto& iter : muertas) {
			if (iter != nullptr)
				delete iter;
		}
	}

};

