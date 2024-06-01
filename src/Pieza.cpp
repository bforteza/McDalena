#include "Pieza.h"
#include "Tablero.h"


Color operator !(Color color) {
	return (color == NEGRO) ? BLANCO : NEGRO;
}


VectorCoordenadas Pieza::premove_dir(Coordenadas(&dir)[4], Tablero* tablero, const Coordenadas& posicion) {

	VectorCoordenadas retorno{};

	Coordenadas aux;
	Coordenadas tam = tablero->get_tam();


	for (auto& d : dir) {			//recorre las direcciones
		aux = posicion;
		aux += d;

		while (aux < tam && tablero->get_pieza(aux) == nullptr) {  //mientras esten vacias
			retorno += aux;
			aux += d;
		}
		if (aux < tam && tablero->get_pieza(aux)->get_color() != color) {  //condicion de diferente color
			retorno += aux;
		}
	}
	
	return retorno;
}


