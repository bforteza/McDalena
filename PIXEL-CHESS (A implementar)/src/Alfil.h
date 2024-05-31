#pragma once
#include "Pieza.h"



class Alfil :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print(int col, int fil, double origenx, double origeny);

    virtual bool premove(Tablero* tablero, int col, int fila);
    friend class Reina;
    virtual Casilla* puntero() { return new Alfil(*this); }

};

