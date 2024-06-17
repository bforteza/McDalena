#pragma once
#include "Pieza.h"



class Peon :
    public Pieza
{
public:
    virtual Pieza* puntero() { return  new Peon(color); }
    virtual void print() { std::cout << ((color) ? "P" : "p"); };
    virtual char puntos() { return 1; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Peon(Color color) : Pieza::Pieza(color) {};
};

