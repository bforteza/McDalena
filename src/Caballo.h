#pragma once
#include "Pieza.h"
class Caballo :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();
    virtual VectorCoordenadas premove(const Tablero* const tablero, const Coordenadas& posicion);
};

