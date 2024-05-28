#pragma once
#include "Pieza.h"
#include "Rey.h"
#include"Torre.h"
#include "Alfil.h"

class Reina :
    public Pieza

{
public:
    using Pieza::Pieza;
    void print();
    bool premove(Rey rey, Alfil al, Tablero* tablero, int col, int fil, Torre tor);
};

