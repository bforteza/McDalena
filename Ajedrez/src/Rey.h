#pragma once
#include "Pieza.h"

class Rey :
    public Pieza
{
    bool move = false;
public:
    using Pieza::Pieza;
    void print();
    bool premove(Tablero* tablero, int col, int fil);
    virtual Casilla* puntero() { return new Rey(*this); }
    friend class Reina;
};
