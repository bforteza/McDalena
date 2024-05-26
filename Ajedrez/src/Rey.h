#pragma once
#include "Pieza.h"
class Rey : public Pieza
{
    std::vector <Casilla*> PosiblesMovimientos{};
public:
    using Pieza::Pieza;
    void print();
    bool premove(Tablero* tablero, Columna col, int fil);
    std::vector <Casilla*> premueve(Tablero* tablero, Columna col, int fil);
};