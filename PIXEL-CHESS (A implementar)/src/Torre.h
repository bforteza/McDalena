#pragma once
#include "Pieza.h"

class Torre :
    public Pieza
{
    bool move = false;
public:
    
    using Pieza::Pieza;
    void print(int col, int fil, double origenx, double origeny);
    bool premove(Tablero* tablero, int col, int fil);
    bool get_move() { return move; }
    virtual Casilla* puntero() { return new Torre(*this); }
};
