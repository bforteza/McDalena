#pragma once
#include "Pieza.h"



class Peon :
    public Pieza
{
public:
    using Pieza::Pieza;
    void print();
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
};
