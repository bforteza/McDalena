#pragma once
#include "Casilla.h"

class CasillaVacia :
    public Casilla // Heredamos la casilla vac�a de manera p�blica de casilla
{
public:

    //Constructores
    CasillaVacia(Color color,Sprite *spr) : Casilla(color, spr) {};
    CasillaVacia();

    void print() final override;
    //Traemos la funci�n de imprimir hasta aqu�
};
