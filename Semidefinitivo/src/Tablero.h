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
	int identificador_coronacion=0;
	bool coronado=false;
	Juego juego;
	vector<Pieza*> cuadricula;
	Coordenadas tam; //tamaño
	vector<Pieza*> muertas;
	VectorCoordenadas p_blancas, p_negras;


	Coordenadas rey(const Color color);
	void borrar_seleccion();
	void asignar(Coordenadas e, Pieza* entrada);
	void buscar_piezas();
	bool fmove(const Coordenadas& origen, const Coordenadas& destino);
	void move(const Coordenadas& e);
	void seleccionar(const VectorCoordenadas&);
	bool jaque(Color color);
	VectorCoordenadas premove(const Coordenadas& e);
public:
	VectorCoordenadas seleccion;
	Coordenadas Piezaamover{ 0,0 };
	Color turno = BLANCO;
	
	Coordenadas get_tam() { return tam; };
	Pieza*& get_pieza(const Coordenadas entrada);
	Pieza* get_pieza(const Coordenadas entrada) const;
	vector<Pieza*>& get_cuadricula();

	void get_coronado(bool &_coronado)
	{
		_coronado=coronado;
	}
	void set_coronado(bool _coronado)
	{
		coronado = _coronado;
	}
	void set_identificador_coronacion(int _identificadorcoronacion)
	{
		identificador_coronacion = _identificadorcoronacion;
	}

	void restart();
	


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

