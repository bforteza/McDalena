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
    friend class Reina;
};
