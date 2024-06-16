#pragma once
#include "Pieza.h"
class Rey :
    public Pieza
{
    bool move = false;
public:
    void gpieza(std::ofstream& out) const;
    void set_tipo() { tipo = "Rey"; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Rey(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
            sprite_pieza = new Sprite("imagenes/ReyB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("imagenes/ReyN.png", 0, 0, 100, 100);
    };
    friend class Tablero;
};

