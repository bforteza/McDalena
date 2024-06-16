#pragma once
#include "Pieza.h"
class Torre :
    public Pieza
{
    bool move = false;
public:
    
   

    virtual char puntos() { return 5; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Torre(Color color) : Pieza::Pieza(color) {};

    friend class Rey;
    friend class Tablero;
};

