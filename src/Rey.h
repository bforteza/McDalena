#pragma once
#include "Pieza.h"
class Rey :
    public Pieza
{
    bool move = false;
public:
   
    virtual char puntos() { return 0; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Rey(Color color) : Pieza::Pieza(color) {};
    friend class Tablero;
};

