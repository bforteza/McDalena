#pragma once
#include "Pieza.h"
class Torre :
    public Pieza
{
    bool move = false;
public:
    
   

  
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Torre(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
            sprite_pieza = new Sprite("bin/imagenes/TorreB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("bin/imagenes/TorreN.png", 0, 0, 100, 100);
    };

    friend class Rey;
    friend class Tablero;
};

