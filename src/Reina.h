#pragma once
#include "Pieza.h"
class Reina :
    public Pieza
{
public:
    virtual Pieza* puntero() { return  new Reina(color); }
    virtual void print() { std::cout << ((color) ? "Q" : "q"); };
    virtual char puntos() { return 9; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);

    Reina(Color color) : Pieza::Pieza(color) {};
        
};

