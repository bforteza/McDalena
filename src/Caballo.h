#pragma once
#include "Pieza.h"
class Caballo :
    public Pieza
{
public:
    virtual void print() { std::cout << ((color) ? "N" : "n"); };
    virtual char puntos() { return 3; }
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);

    Caballo(Color color) : Pieza::Pieza(color) {};
      

};
