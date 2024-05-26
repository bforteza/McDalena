#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
private:
    int movimientos{};
    std::vector <Casilla*> PosiblesMovimientos{};
public:
    using Pieza::Pieza;
    void print();
    std::vector <Casilla*> premueve(Tablero* tablero, Columna col, int fil);
    
};

