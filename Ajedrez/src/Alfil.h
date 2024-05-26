#pragma once
#include "Pieza.h"



class Alfil :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();

    virtual bool premove(Tablero* tablero,Columna col, int fila);

};

