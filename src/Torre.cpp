#include "Torre.h"


void Torre::print( const float x, const float y, const float lado) {

    if (color == NEGRO)
    {
       
        sprite_pieza = new Sprite("bin/imagenes/TorreN.png", x, y, lado , lado);
    }
    if (color == BLANCO)
    {
       
        sprite_pieza = new Sprite("bin/imagenes/TorreB.png", x, y, lado , lado);

    }
    sprite_pieza->draw();
}



VectorCoordenadas Torre::premove(Tablero* tablero, const Coordenadas& posicion)
{
	Coordenadas direcciones[4] = { {0,1},{0,-1},{1,0},{-1,0} };
	return Pieza::premove_dir(direcciones, tablero, posicion);
}
