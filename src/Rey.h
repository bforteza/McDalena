#pragma once
#include "Pieza.h"
class Rey :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
};

