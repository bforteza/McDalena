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
	
	vector<Pieza*> cuadricula;

	Coordenadas tam; //tamaño
	vector<Pieza*> muertas;
	VectorCoordenadas seleccion, p_blancas, p_negras;


	

	void asignar(Coordenadas e, Pieza* entrada);
	void buscar_piezas();
	bool fmove(const Coordenadas& origen, const Coordenadas& destino);
	Coordenadas Piezaamover{0,0};
	Color turno = BLANCO;

public:

	

	Coordenadas get_tam() { return tam; };
	Pieza*& get_pieza(const Coordenadas entrada);
	Pieza* get_pieza(const Coordenadas entrada) const;
	Coordenadas rey(const Color color);




	bool jaque(Color color);
	void seleccionar(const VectorCoordenadas&);
	void borrar_seleccion();

	VectorCoordenadas premove(const Coordenadas& e);
	void move(const Coordenadas& e);

	void entrada(const Coordenadas& e);
	//inicializadores
	Tablero(Juego juego);

	friend class VentanaTablero;
};

