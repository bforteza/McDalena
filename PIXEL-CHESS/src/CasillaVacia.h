#pragma once
#include "Casilla.h"

class CasillaVacia :
    public Casilla // Heredamos la casilla vac�a de manera p�blica de casilla
{
public:

    //Constructores
    CasillaVacia(Color color,Sprite *spr, Vector2D coord) : Casilla(color, spr,coord) {};
    CasillaVacia();

    void print() final override;
    //Traemos la funci�n de imprimir hasta aqu�
};
