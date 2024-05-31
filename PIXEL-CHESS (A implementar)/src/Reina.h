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
    void print(int col, int fil, double origenx, double origeny);
    bool premove( Tablero* tablero, int col, int fil);
    virtual Casilla* puntero() { return new Reina(*this); }
};

