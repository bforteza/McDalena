#include "Rey.h"
#include "Tablero.h"

VectorCoordenadas Rey::premove(Tablero* tablero, const Coordenadas& posicion)
{
	VectorCoordenadas retorno;
	Coordenadas dir(posicion);
	Coordenadas tam = tablero->get_tam();
	Pieza* aux;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {

			dir = posicion;
			dir += Coordenadas{ i, j };

			if (dir < tam) {
				aux = tablero->get_pieza(dir);
				if (aux == nullptr) {
					retorno += dir;
				}
				else if (aux->get_color() != color) {
					retorno += dir;
				}
			}
		}
	}
	if (!move) {
		Torre* Tizq = dynamic_cast<Torre*>(tablero->get_pieza(posicion + Coordenadas(-3, 0)));
		Torre* Tder = dynamic_cast<Torre*>(tablero->get_pieza(posicion + Coordenadas(+3, 0)));
		if (( Tizq != nullptr && !Tizq->move && (tablero->get_pieza(posicion + Coordenadas(-2, 0))) == nullptr
			&& (tablero->get_pieza(posicion + Coordenadas(-1, 0))) == nullptr    ))
			retorno += posicion + Coordenadas(-2, 0);
		if ((Tder != nullptr && !Tder->move) && (tablero->get_pieza(posicion + Coordenadas(+2, 0))) == nullptr
			&& (tablero->get_pieza(posicion + Coordenadas(+1, 0))) == nullptr)  
			retorno += posicion + Coordenadas(+2, 0);
	}

	return retorno;

}

void Rey::gpieza(std::ofstream& out) const {
	out << static_cast<int>(color) << tipo << std::endl;
}