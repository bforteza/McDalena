#include "Rey.h"
#include "Tablero.h"
void Rey::print(int col, int fil, double origenx, double origeny) {


		if (color == NEGRO)
		{
			sprite_pieza = new Sprite("imagenes/ReyN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
		if (color == BLANCO)
		{
			sprite_pieza = new Sprite("imagenes/ReyB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
	sprite_pieza->draw();
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


	return retorno;

}
