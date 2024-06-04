#pragma once
#include <vector>
#include "Coordenadas.h"
#include <iostream>
#include "ETSIDI.h"
#include "Pieza.h"

class CasillaVacia
{
    Sprite* sprite_casilla{}; //Sprite Correspondiente
    Color color;
    bool verde = false;
    bool rojo = false;

public:
    CasillaVacia(Color _color) : color(_color) {};
    
    void set_verde();
    void set_rojo();

    virtual void print(const float x, const float y, const float lado) ;
};