#pragma once
#include "Pieza.h"
class Alfil :
    public Pieza
{
public:
   

    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Alfil(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
            sprite_pieza = new Sprite("bin/imagenes/AlfilB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("bin/imagenes/AlfilN.png", 0, 0, 100, 100);
    };
};

