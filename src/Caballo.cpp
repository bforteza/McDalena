#include "Caballo.h"
#include "Tablero.h"
void Caballo::print() {

	std::cout << ((color == NEGRO) ? "N" : "n");
}

VectorCoordenadas Caballo::premove(const Tablero* const tablero, const Coordenadas& posicion)
{
	VectorCoordenadas retorno({{1,2},{2,1},{-1,-2},{-1,-2},{1,-2},{-2,1},{-1,2},{2,-1}});
	Coordenadas tam = tablero->get_tam();
	for (auto& iter : retorno.v) {
		iter += posicion;
	}
	for (auto iter : std::vector(retorno.v)) {
		if (!((iter + posicion) < tam) || tablero->get_pieza(iter)->get_color() == color)
			retorno.eliminar(iter);
	}

	return retorno;
}

