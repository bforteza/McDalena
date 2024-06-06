#pragma once
#include <iostream>
#include <freeglut.h>
#include <ETSIDI.h>
#include "Tablero.h"
#include <vector>
#include <Menu.h>
#include <iostream>
#include <fstream>
#include <string>

class Partida
{
private:
	vector <Pieza*>posicionesg{};
	vector <Pieza*>posicionesc{};

public:
	void guardar(Tablero& tab);
	void cargar(vector<Pieza*>& piezas, Juego juego);
};

