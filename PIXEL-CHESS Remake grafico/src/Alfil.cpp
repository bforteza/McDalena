#include "Alfil.h"

void Alfil::print(int col, int fil, double origenx, double origeny) {

	//std::cout << ((color_pieza == NEGRO) ? "A" : "a");
		if (color == NEGRO)
		{
			sprite_pieza = new Sprite("imagenes/AlfilN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.45, 0.8, 0.8);
		}
		if (color == BLANCO)
		{
			sprite_pieza = new Sprite("imagenes/AlfilB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.45, 0.8, 0.8);

		}

	sprite_pieza->draw();



}

VectorCoordenadas Alfil::premove(Tablero* tablero, const Coordenadas& posicion)
{
	Coordenadas direcciones[4] = { {1,1},{1,-1},{-1,-1},{-1,1} };

	return Pieza::premove_dir(direcciones, tablero, posicion);

}

void Alfil::gpieza(std::ofstream& out) const {
	out << static_cast<int>(color) << tipo << std::endl;
}
