#pragma once
#include "Pieza.h"

class Torre :
    public Pieza
{
    bool move = false;
public:
    
    using Pieza::Pieza;
    void print();
    bool premove(Tablero* tablero, Columna col, int fil);
    bool get_move() { return move; }
    
};
