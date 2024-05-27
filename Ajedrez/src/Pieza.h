#pragma once

#include "Casilla.h"


class Pieza :
    public Casilla
{
protected:
    Color color_pieza{};
public:
    virtual Color get_color_pieza() { return color_pieza; };
    Pieza(Color pieza) : Casilla(NEGRO), color_pieza(pieza) {};
    virtual void print() {};
    virtual bool ocupado() { return true; };
    virtual bool premove(Tablero* tablero, int col, int fil) { return false; };
};

