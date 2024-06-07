#pragma once
#include <vector>
#include "Coordenadas.h"
#include <iostream>
#include "ETSIDI.h"
#include "Pieza.h"

class CasillaVacia
{
    Sprite* sprite_casilla{}; //Sprite Correspondiente  
    float lado;
    bool verde = false;
    bool rojo = false;
    bool azul = false;

    Sprite casilla, casilla_verde, casilla_roja,casilla_azul;

public:
    Color color;
    CasillaVacia(Color _color, float _lado) : color(_color) , lado(_lado),
    casilla((_color == BLANCO) ? "bin/imagenes/cuadrado.png" : "bin/imagenes/cuadrado2.png", 0, 0 , lado, lado ),
    casilla_verde("bin/imagenes/BlancoTenue.png",0,0,lado,lado),
    casilla_azul("bin/imagenes/NegroTenue.png", 0, 0, lado, lado),
    casilla_roja("bin/imagenes/cuadradoverde.png",0,0, lado , lado)
    {
    
    
    };
    
    void set_verde();
    void set_rojo();
    void set_azul();

    virtual void print(const float x, const float y) ;
};