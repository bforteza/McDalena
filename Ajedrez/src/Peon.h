#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
private:
    int movimientos{};

public:
    using Pieza::Pieza;
    void print();
    bool premueve(Tablero* tablero, Columna col, int fil);
};