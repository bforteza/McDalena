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

	VectorCoordenadas seleccion,p_blancas, p_negras;

	void asignar(Coordenadas e, Pieza* entrada);
	void buscar_piezas();
public:
	
	//parametros
	Coordenadas get_tam() { return tam; };
	Pieza*& get_pieza(Coordenadas entrada);
	Coordenadas rey(Color color);
	
	void print();


	void seleccionar(const VectorCoordenadas&);
	void borrar_seleccion();
	

	VectorCoordenadas premove(const Coordenadas& e);

	//inicializadores
	Tablero(Juego juego);
};

