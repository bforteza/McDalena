#pragma once
#include "Casilla.h"

class CasillaVacia :
    public Casilla // Heredamos la casilla vacía de manera pública de casilla
{
public:

    //Constructores
    CasillaVacia(Color color,Sprite *spr, Vector2D coord) : Casilla(color, spr,coord) {};
    CasillaVacia();

    void print() final override;
    //Traemos la función de imprimir hasta aquí
};
