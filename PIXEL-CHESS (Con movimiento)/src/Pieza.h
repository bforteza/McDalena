#pragma once

#include "Casilla.h"


class Pieza :
    public Casilla
{
protected:
    Color color_pieza{};
public:
    virtual Color get_color_pieza() { return color_pieza; };
    Pieza(Color pieza,Color casilla = NEGRO) : Casilla(casilla), color_pieza(pieza) {};
    Pieza(const Pieza& otra) : Casilla(otra.color_casilla), color_pieza(otra.color_pieza) {};
    void print(int col, int fil, double origenx, double origeny) {};
    virtual bool ocupado() { return true; };
    
    virtual bool premove(Tablero* tablero, int col, int fil) { return false; };
    virtual void mover(Tablero* tablero, int posx, int posy, int cvx, int cvy) {};
};

