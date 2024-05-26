#pragma once
#include "Pieza.h"

class Torre :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();
    bool premueve(Tablero* tablero, Columna col, int fil);
};

