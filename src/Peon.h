#pragma once
#include "Pieza.h"



class Peon :
    public Pieza
{
public:
    void set_tipo() { tipo = "Peon"; }
    void gpieza(std::ofstream& out) const;
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Peon(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
            sprite_pieza = new Sprite("bin/imagenes/PeonB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("bin/imagenes/PeonN.png", 0, 0, 100, 100);
    };
};

