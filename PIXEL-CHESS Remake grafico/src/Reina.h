#pragma once
#include "Pieza.h"
class Reina :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print(int col, int fil, double origenx, double origeny);
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
};

