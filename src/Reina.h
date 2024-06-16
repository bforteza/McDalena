#pragma once
#include "Pieza.h"
class Reina :
    public Pieza
{
public:
    
    virtual char puntos() { return 9; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);

    Reina(Color color) : Pieza::Pieza(color) {};
        
};

