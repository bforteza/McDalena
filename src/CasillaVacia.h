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
    float lado;
    bool verde = false;
    bool rojo = false;

    Sprite casilla, casilla_verde, casilla_roja;

public:
    CasillaVacia(Color _color, float _lado) : color(_color) , lado(_lado),
    casilla((_color == BLANCO) ? "bin/imagenes/cuadrado.png" : "bin/imagenes/cuadrado2.png", 0, 0 , lado, lado ),
    casilla_verde("bin/imagenes/cuadradoverde.png",0,0,lado,lado),
    casilla_roja("bin/imagenes/cuadradorojo.png",0,0, lado , lado)
    {
    
    
    };
    
    void set_verde();
    void set_rojo();

    virtual void print(const float x, const float y) ;
};