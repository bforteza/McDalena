#pragma once
#include "ETSIDI.h"
#include "Casilla.h"
#include <vector>
#include <iomanip>
#include <array>
using namespace std;
class Tablero
{
public:

	std::vector<std::array<Casilla, 4>> casillas;

	void inicializa();
	void dibuja();
};

