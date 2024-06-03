#pragma once
#include "Pieza.h"
class Torre :
    public Pieza
{
    bool move = false;
    friend class Rey;
public:
    using Pieza::Pieza;
    void print();
    
        
    virtual VectorCoordenadas premove(const Tablero* const tablero, const Coordenadas& posicion);
};

