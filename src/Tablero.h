#pragma once
#include "Pieza.h"
#include "Peon.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Torre.h"
#include "Caballo.h"

enum Juego{UP,SC};
class Tablero
{
private:
	vector<Pieza*> cuadricula;
	Coordenadas tam;				//tamaño
	vector<Pieza*> muertas;			//piezas muertas
	VectorCoordenadas seleccion,p_blancas, p_negras; 

	void asignar(Coordenadas e, Pieza* entrada);
	void buscar_piezas();
	bool fmove(const Coordenadas& origen, const Coordenadas& destino); //devuelve true si ha muerto alguna pieza
	Coordenadas rey(Color color)const;
public:

	//parametros
	Coordenadas get_tam() const { return tam; };
	Pieza*& get_pieza(const Coordenadas entrada);
	Pieza* get_pieza(const Coordenadas entrada) const;

	
	void print();

	bool mate(Color color);
	bool ahogado(Color color);
	bool jaque(Color color);
	void seleccionar(const VectorCoordenadas&);
	void borrar_seleccion();
	
	VectorCoordenadas premove(const Coordenadas& e);
	void jugar();
	//inicializadores
	Tablero(Juego juego);
	~Tablero(){
		for (auto& iter : cuadricula) {
			if (iter != nullptr)
				delete iter;
		}
		cuadricula.clear();
		for (auto& iter : muertas) {
			if (iter != nullptr)
				delete iter;
		}
		muertas.clear();
	}
};

