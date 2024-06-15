#pragma once
#include "Pieza.h"
class Caballo :
    public Pieza
{

public:
    void set_tipo() { tipo = "Caballo"; }
    void gpieza(std::ofstream& out) const;
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);

    Caballo(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
        sprite_pieza = new Sprite("bin/imagenes/CaballoB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("bin/imagenes/CaballoN.png", 0, 0, 100, 100);
    };

};
