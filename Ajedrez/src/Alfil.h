#pragma once
#include "Pieza.h"



class Alfil :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();

    virtual bool premove(Tablero* tablero, int col, int fila);
    friend class Reina;
    virtual Casilla* puntero() { return new Alfil(*this); }

};

