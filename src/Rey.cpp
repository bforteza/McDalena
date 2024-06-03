#include "Rey.h"
#include "Tablero.h"
void Rey::print() {

	std::cout << ((color == NEGRO) ? "K" : "k");
}

VectorCoordenadas Rey::premove(const Tablero* const tablero, const Coordenadas& posicion)
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
				if(aux == nullptr)  {
					retorno += dir;
				}
				else if (aux->get_color() != color) {
					retorno += dir;
				}
			}
		}
	}
	
	if (!move) {
		Torre* Tizq = dynamic_cast<Torre*>(tablero->get_pieza(posicion + Coordenadas(-2, 0)));
		Torre* Tder = dynamic_cast<Torre*>(tablero->get_pieza(posicion + Coordenadas(+2, 0)));
		if ((Tizq != nullptr && !Tizq->move))
			retorno += posicion + Coordenadas(-2, 0);
		if ((Tder != nullptr && !Tder->move))
			retorno += posicion + Coordenadas(+2, 0);
	}
	return retorno;	
}
