#pragma once
#include "Casilla.h"
class Pieza :
    public Casilla
{
protected:
    Color color_pieza{};
public:
    Pieza(Color pieza) : Casilla(NEGRO), color_pieza(pieza) {};
};

