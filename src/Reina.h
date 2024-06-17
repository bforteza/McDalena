#pragma once
#include "Pieza.h"
class Reina :
    public Pieza
{
public:
    void gpieza(std::ofstream& out) const;
    void set_tipo() { tipo = "Reina"; }

    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);

    Reina(Color color) : Pieza::Pieza(color) {
        if (color == BLANCO)
            sprite_pieza = new Sprite("imagenes/ReinaB.png", 0, 0, 100, 100);
        if (color == NEGRO)
            sprite_pieza = new Sprite("imagenes/ReinaN.png", 0, 0, 100, 100);
    };

};

