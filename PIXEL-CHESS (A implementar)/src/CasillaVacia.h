#pragma once
#include "Casilla.h"
#include "Tablero.h"

class CasillaVacia :
    public Casilla
   
{
public:

    CasillaVacia(Color color) : Casilla(color) {};
    virtual bool premove(Tablero* tablero, int col, int fil) { return false; };
    virtual bool ocupado() { return false; };
    virtual Casilla* puntero() { return new CasillaVacia(color_casilla); };
  
    void print(int col, int fil,double origenx, double origeny);
};

