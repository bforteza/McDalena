#include "Rey.h"
#include "Tablero.h"
void Rey::print() {

	std::cout << ((color == NEGRO) ? "K" : "k");
}

VectorCoordenadas Rey::premove(Tablero* tablero, const Coordenadas& posicion)
{
	VectorCoordenadas retorno;
	Coordenadas dir(posicion);
	Coordenadas tam = tablero->get_tam();
	Pieza* aux;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			dir = posicion;
			dir += Coordenadas{i, j};
			if (dir < tam) {
				aux = tablero->get_pieza(dir);
				if(aux != nullptr)  {
					retorno += new Coordenadas(dir);
				}
				else if (aux->get_color() != color) {
					retorno += new Coordenadas(dir);
				}
			}
		}
	}


	return retorno;
	
}
