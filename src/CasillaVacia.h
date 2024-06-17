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

    Sprite casilla, casilla_verde, casilla_seleccionada;

public:
    Color color;
    CasillaVacia(Color _color, float _lado) : color(_color), lado(_lado),
        casilla((_color == BLANCO) ? "imagenes/cuadrado.png" : "imagenes/cuadrado2.png", 0, 0, lado, lado),
        casilla_verde("imagenes/cuadradoverde.png", 0, 0, lado, lado),
        casilla_seleccionada((_color == BLANCO) ? "imagenes/BlancoTenue.png" : "imagenes/NegroTenue.png", 0, 0, lado, lado)
    {


    };

    void set_verde();
    void set_selecionado();

    virtual void print(const float x, const float y);
};