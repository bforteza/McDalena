#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
private:
    int movimientos{};

public:
    using Pieza::Pieza;
    void print();
    bool premove(Tablero* tablero, Columna col, int fil);
};