#pragma once
#include "Pieza.h"
class Alfil :
    public Pieza
{
public:
    using Pieza::Pieza;
   virtual void print( const float x, const float y, const float lado) ;
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
};

