#pragma once
#include "Pieza.h"

class Torre :
    public Pieza
{
    std::vector <Casilla*> PosiblesMovimientos{};
public:
    using Pieza::Pieza;
    void print();
    std::vector <Casilla*> premueve(Tablero* tablero, Columna col, int fil);
};

