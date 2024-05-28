#pragma once
#include "Pieza.h"
class Caballo :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();
    bool premove(Tablero* tablero, int col, int fil);

};

