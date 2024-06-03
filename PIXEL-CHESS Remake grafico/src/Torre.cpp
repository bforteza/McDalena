#include "Torre.h"


void Torre::print(int col, int fil, double origenx, double origeny) {

    if (color == NEGRO)
    {
       
        sprite_pieza = new Sprite("imagenes/TorreN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.40, 0.8, 0.8);
    }
    if (color == BLANCO)
    {
       
        sprite_pieza = new Sprite("imagenes/TorreB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.40, 0.8, 0.8);

    }
    sprite_pieza->draw();
}



VectorCoordenadas Torre::premove(Tablero* tablero, const Coordenadas& posicion)
{
	Coordenadas direcciones[4] = { {0,1},{0,-1},{1,0},{-1,0} };
	return Pieza::premove_dir(direcciones, tablero, posicion);
}
