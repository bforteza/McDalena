#pragma once
#include "Pieza.h"

class Peon : public Pieza
{


public:
    using Pieza::Pieza;
    void  print(int col, int fil, double origenx, double origeny);
    bool premove(Tablero* tablero, int col, int fil);
    virtual Casilla* puntero() { return new Peon(*this); }
};