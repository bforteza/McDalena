#pragma once
#include "Pieza.h"



class Peon :
    public Pieza
{
public:
   
    virtual char puntos() { return 1; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Peon(Color color) : Pieza::Pieza(color) {};
};

