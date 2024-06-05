#pragma once
#include "Pieza.h"



class Peon :
    public Pieza
{
    std::string tipo = "Peon";
public:
    using Pieza::Pieza;
    void print(int col, int fil, double origenx, double origeny);
    virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion);
    void gpieza(std::ofstream& out) const;
};

