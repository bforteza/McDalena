#pragma once
#include "Pieza.h"
class Alfil :
    public Pieza
{
    std::string tipo = "Alfil";
public:
    using Pieza::Pieza;
    void print(int col, int fil, double origenx, double origeny);
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    void gpieza(std::ofstream& out) const;
};

