#pragma once
#include "Casilla.h"

class CasillaVacia :
    public Casilla
{
public:

    CasillaVacia(Color color) : Casilla(color) {};

    void print();
};

