#pragma once
#include <vector>
#include "Casilla.h"
#include "Tablero.h"
#include "vector"


class Pieza :
    public Casilla
{
protected:
    Color color_pieza{};
public:
    Pieza(Color pieza) : Casilla(NEGRO), color_pieza(pieza) {};
    virtual void print() = 0;
    virtual bool ocupado() { return true; };
    virtual bool premove(Tablero* tablero, Columna col, int fil) { return false; };
};

