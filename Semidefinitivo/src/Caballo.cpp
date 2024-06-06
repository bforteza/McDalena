#include "Caballo.h"
#include "Tablero.h"



VectorCoordenadas Caballo::premove(Tablero* tablero, const Coordenadas& posicion)
{
	VectorCoordenadas direcciones({ {1,2},{2,1},{-1,-2},{-1,-2},{1,-2},{-2,1},{-1,2},{2,-1} });
	Coordenadas tam = tablero->get_tam();
	VectorCoordenadas retorno;
	for (auto& iter : direcciones.v) {
		iter += posicion;
	}
	for (auto iter : std::vector<Coordenadas>(direcciones.v)) {
		if ((iter < tam) && tablero->get_pieza(iter) == nullptr)
			retorno += iter;
		else if((iter < tam) && tablero->get_pieza(iter)->get_color() != color)
			retorno += iter;
	}

	return retorno;
}

void Caballo::gpieza(std::ofstream& out) const {
	out << static_cast<int>(color) << tipo << std::endl;
}
