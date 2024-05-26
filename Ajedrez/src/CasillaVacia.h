#pragma once
#include "Casilla.h"
#include "Tablero.h"

class CasillaVacia :
    public Casilla
{
public:

    CasillaVacia(Color color) : Casilla(color) {};
    virtual bool premove(Tablero* tablero, Columna col, int fil) { return false; };
    virtual bool ocupado() { return false; };
    void print();
};

