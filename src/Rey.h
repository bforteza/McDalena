#pragma once
#include "Pieza.h"
class Rey :
    public Pieza
{
    bool move = false;
public:
    using Pieza::Pieza;
    void print();
    virtual VectorCoordenadas premove(const Tablero* const tablero, const Coordenadas& posicion);
};

