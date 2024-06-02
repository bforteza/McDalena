#pragma once
#include "Pieza.h"

class Rey :
    public Pieza
{
    bool move = false;
public:
    using Pieza::Pieza;
    void print(int col, int fil, double origenx, double origeny);
    bool premove(Tablero* tablero, int col, int fil);
    virtual void mover(Tablero* tablero, int posx, int posy, int cvx, int cvy);
    virtual Casilla* puntero() { return new Rey(*this); }
    friend class Reina;
};
