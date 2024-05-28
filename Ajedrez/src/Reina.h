#pragma once
#include "Pieza.h"
#include "Rey.h"
#include"Torre.h"
#include "Alfil.h"

class Reina :
    public Pieza

{
public:
    using Pieza::Pieza;
    void print();
    bool premove( Tablero* tablero, int col, int fil);
    virtual Casilla* puntero() { return new Reina(*this); }
};

