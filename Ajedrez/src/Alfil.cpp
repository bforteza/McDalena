#include "Alfil.h"

#include "Tablero.h"

void Alfil::print() {

	std::cout << ((color_pieza == NEGRO) ? "A" : "a");
}

bool Alfil::premove(Tablero* tablero, int columna, int fila) {
	int col = columna;
	int fil = fila;
	bool retorno = false;
	
	Casilla* aux;
	for (int auxcol = -1;auxcol <= 1; auxcol += 2) {    
		for (int auxfil = -1; auxfil <= 1; auxfil += 2) {   //recorre las cuatro diagonales
			col = columna; //volver a la casilla de inicio
			fil = fila;
			aux = tablero->get_casilla(col + auxcol, fil + auxfil); //Diagonal 
			while (aux != nullptr && !aux->ocupado()) {
				retorno = true;
				aux->selecionada = true;
				col+= auxcol;
				fil+= auxfil;
				aux = tablero->get_casilla(col + auxcol, fil + auxfil);
			}
			//Prueba si la ultima pieza ocupada es de su color o del contrario
			if (aux != nullptr && aux->ocupado() && dynamic_cast<Pieza*>(aux)->get_color_pieza() != color_pieza) { 
				aux->selecionada = true;
				retorno = true;
			}
		}
	}
	return retorno;
}