#pragma once
#include "Pieza.h"
class Torre :
    public Pieza
{
    bool move = false;
public:
    void gpieza(std::ofstream& out) const;
    void set_tipo() { tipo = "Torre"; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Torre(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
            sprite_pieza = new Sprite("imagenes/TorreB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("imagenes/TorreN.png", 0, 0, 100, 100);
    };

    friend class Rey;
    friend class Tablero;
};

