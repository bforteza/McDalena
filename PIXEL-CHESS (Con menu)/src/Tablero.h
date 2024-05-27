#pragma once
#include "ETSIDI.h"
#include "Casilla.h"
#include <vector>
#include <iomanip>
#include <array>
#include <Pieza.h>
#include <Peon.h>
#include <Torre.h>
#include <Caballo.h>
#include<Alfil.h>
#include<Rey.h>
#include<Reina.h>
enum Columna { A = 0, B, C, D, E, F, G };
//Columna que corresponde a una coordenada x
class Tablero
{
	 float origenx, origeny;
	 float marca_origenx,marca_origeny;
	 int marca_filas, marca_columnas,marca_spritex,marca_spritey;
	 int spriteorigenx, spriteorigeny;
	 int modalidad;
	// Matriz de casillas que conforman el tablero
		std::vector<std::vector< Casilla*>> cuadricula;
	 Sprite volver = { "imagenes/PreVolver.png", -3,3,1, 1 };

	 Torre *TorreBlanca,*TorreNegra;
	 Caballo *CaballoBlanco, *CaballoNegro;
	 Alfil* AlfilBlanco, * AlfilNegro;
	 Rey* ReyBlanco, * ReyNegro;
	 Reina* ReinaBlanca, * ReinaNegra;
	 std::vector< Peon*> PeonesBlancos, PeonesNegros;
	
public:

	//Constructores
	Tablero(Columna columnas, int filas,
		const float origen_x, const float origen_y,
		const int spriteorigen_x, const int spriteorigen_y,
		int _modalidad);
	Tablero() = default;

	//Método de inicialización de casilla
	Casilla& casilla(Columna col, int fil);
	void dibujafondo();
	void dibuja();
	void detectar(int x, int y);
	void clicar(int x, int y, int &estado);
};
