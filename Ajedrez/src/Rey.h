#pragma once
#include "Pieza.h"

class Rey :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();
    bool premove(Tablero* tablero, Columna col, int fil);
    friend class Reina;
};
