#pragma once
#include "Pieza.h"
class Rey :
    public Pieza
{
    bool move = false;
public:
   
   
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Rey(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
            sprite_pieza = new Sprite("bin/imagenes/ReyB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("bin/imagenes/ReyN.png", 0, 0, 100, 100);
    };
};

