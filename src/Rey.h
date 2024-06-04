#pragma once
#include "Pieza.h"
class Rey :
    public Pieza
{
    bool move = false;
public:
    using Pieza::Pieza;
   virtual void print( const float x, const float y, const float lado) ;
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
};

