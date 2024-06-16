#pragma once
#include "Pieza.h"
class Caballo :
    public Pieza
{
public:
   
    virtual char puntos() { return 3; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);

    Caballo(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
        sprite_pieza = new Sprite("imagenes/CaballoB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("imagenes/CaballoN.png", 0, 0, 100, 100);
    };

};
