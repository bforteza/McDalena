#pragma once
#include <vector>
#include "Coordenadas.h"
#include <iostream>
#include "ETSIDI.h"
#include "Pieza.h"

class CasillaVacia: public Pieza
{

public:
    CasillaVacia(Color color) : Pieza(color) {};
    //virtual bool premove(Tablero* tablero, int col, int fil) { return false; };
    //virtual bool ocupado() { return false; };
    //virtual Pieza* puntero() { return new CasillaVacia(color); };

    virtual void print(int col, int fil, double origenx, double origeny);
};