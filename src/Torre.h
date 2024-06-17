#pragma once
#include "Pieza.h"
class Torre :
    public Pieza
{
    bool move = false;
public:
    virtual Pieza* puntero() { return  new Torre(color,move); }
   
    virtual void print() { std::cout << ((color) ? "R" : "r"); };
    virtual char puntos() { return 5; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    Torre(Color color, bool estado=0) : Pieza::Pieza(color), move(estado) {};

    friend class Rey;
    friend class Tablero;
};

