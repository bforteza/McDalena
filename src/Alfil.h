#pragma once
#include "Pieza.h"
class Alfil :
    public Pieza
{
public:
   
    virtual char puntos() { return 3; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Alfil(Color color) : Pieza::Pieza(color) {};
};

