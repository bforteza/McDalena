#pragma once
#include "Pieza.h"
class Rey :
    public Pieza
{
    bool move = false;
public:
    virtual Pieza* puntero() { return  new Rey(color, move); }
    virtual void print() { std::cout << ((color) ? "K" : "k"); };
    virtual char puntos() { return 0; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Rey(Color color, bool estado = false) : Pieza::Pieza(color), move(estado) {};
    friend class Tablero;
};

