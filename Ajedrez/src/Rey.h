#pragma once
#include "Pieza.h"

class Rey :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();
    bool premueve(Tablero* tablero, Columna col, int fil);
};