#pragma once
#include "Casilla.h"

class CasillaVacia :
    public Casilla // Heredamos la casilla vacía de manera pública de casilla
{
public:

    //Constructores
    CasillaVacia(Color color,Sprite *spr) : Casilla(color, spr) {};
    CasillaVacia();

    void print() final override;
    //Traemos la función de imprimir hasta aquí
};
