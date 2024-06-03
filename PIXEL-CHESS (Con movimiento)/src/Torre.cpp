#include "Torre.h"
#include "Tablero.h"
#include <iostream>

void Torre::print(int col, int fil, double origenx, double origeny) {

    if (color_casilla == NEGRO)
    {
        if (color_pieza == NEGRO)
        {
            sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
            sprite_pieza = new Sprite("imagenes/TorreN.png",1.66+origenx+ fil * 1.072 - 1.65,-2.5+origeny -1.072 * col + 2.40, 0.8, 0.8);
        }
        if (color_pieza == BLANCO)
        {
            sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
            sprite_pieza = new Sprite("imagenes/TorreB.png",1.66+origenx+ fil * 1.072 - 1.65,-2.5+origeny -1.072 * col + 2.40, 0.8, 0.8);

        }
    }
    if (color_casilla == BLANCO)
    {
        if (color_pieza == NEGRO)
        {
            sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
            sprite_pieza = new Sprite("imagenes/TorreN.png",1.66+origenx+ fil * 1.072 - 1.65,-2.5+origeny -1.072 * col + 2.40, 0.8, 0.8);

        }
        if (color_pieza == BLANCO)
        {
            sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
            sprite_pieza = new Sprite("imagenes/TorreB.png",1.66+origenx+ fil * 1.072 - 1.65,-2.5+origeny -1.072 * col + 2.40, 0.8, 0.8);

        }
    }
    if (color_casilla == VERDE)
    {
        if (color_pieza == NEGRO)
        {
            sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
            sprite_pieza = new Sprite("imagenes/TorreN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.45, 0.8, 0.8);

        }
        if (color_pieza == BLANCO)
        {
            sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
            sprite_pieza = new Sprite("imagenes/TorreB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.45, 0.8, 0.8);

        }
    }
    if (color_casilla == ROJO)
    {
        if (color_pieza == NEGRO)
        {
            sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
            sprite_pieza = new Sprite("imagenes/TorreN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

        }
        if (color_pieza == BLANCO)
        {
            sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
            sprite_pieza = new Sprite("imagenes/TorreB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

        }
    }
    sprite_pieza->draw();
    sprite_casilla->draw();
    }
   

bool Torre::premove(Tablero* tablero, int col, int fil) {
    bool retorno = false;
    // Mover hacia la derecha
    
    if (color_pieza == BLANCO) {
        
        if (tablero->contador % 2 == 0) {

            retorno = false;
        }

        else if (tablero->contador % 2 != 0) {

            
      
    
            for (int i = col + 1; i < 8; ++i)
            {
                Casilla* casilla = tablero->get_casilla(i, fil);
                if (casilla != nullptr && casilla->ocupado())
                {

                    if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
                    {
                        casilla->color_casilla = ROJO;
                        casilla->selecionada = true; // Puede capturar la pieza enemiga
                        retorno = true;
                    }
                    break; // Detenerse al encontrar una pieza
                }
                else {
                    if (casilla != nullptr)
                    {
                        casilla->color_casilla = ROJO;
                        casilla->selecionada = true; // Casilla vacía
                        retorno = true;
                    }
                }
            }

            // Mover hacia la izquierda
            for (int i = col - 1; i >= 0; --i)
            {
                Casilla* casilla = tablero->get_casilla(i, fil);
                if (casilla != nullptr && casilla->ocupado())
                {

                    if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
                    {
                        casilla->color_casilla = ROJO;
                        casilla->selecionada = true; // Puede capturar la pieza enemiga
                        retorno = true;
                    }
                    break; // Detenerse al encontrar una pieza
                }
                else {
                    if (casilla != nullptr) {
                        casilla->color_casilla = ROJO;
                        casilla->selecionada = true; // Casilla vacía
                        retorno = true;
                    }
                }
            }

            // Mover hacia arriba
            for (int i = fil + 1; i < 8; ++i)
            {

                Casilla* casilla = tablero->get_casilla(col, i);
                if (casilla != nullptr && casilla->ocupado())
                {

                    if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
                    {
                        casilla->color_casilla = ROJO;
                        casilla->selecionada = true; // Puede capturar la pieza enemiga
                    }
                    break; // Detenerse al encontrar una pieza
                }
                else {
                    if (casilla != nullptr) {
                        casilla->color_casilla = ROJO;
                        casilla->selecionada = true; // Casilla vacía
                        retorno = true;
                    }
                }
            }

            // Mover hacia abajo
            for (int i = fil - 1; i >= 0; --i)
            {
                Casilla* casilla = tablero->get_casilla(col, i);
                if (casilla != nullptr && casilla->ocupado())
                {
                    if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
                    {
                        casilla->color_casilla = ROJO;
                        casilla->selecionada = true; // Puede capturar la pieza enemiga
                    }
                    break; // Detenerse al encontrar una pieza
                }
                else {
                    if (casilla != nullptr) {
                        casilla->color_casilla = ROJO;
                        casilla->selecionada = true; // Casilla vacía
                        retorno = true;
                    }
                }
            }

            return retorno; 
        
        }
     }
 

        else if (color_pieza == NEGRO) {

            if (tablero->contador % 2 != 0) {

                retorno = false;
            }

            if (tablero->contador % 2 == 0) {

                for (int i = col + 1; i < 8; ++i)
                {
                    Casilla* casilla = tablero->get_casilla(i, fil);
                    if (casilla != nullptr && casilla->ocupado())
                    {

                        if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
                        {
                            casilla->color_casilla = ROJO;
                            casilla->selecionada = true; // Puede capturar la pieza enemiga
                            retorno = true;
                        }
                        break; // Detenerse al encontrar una pieza
                    }
                    else {
                        if (casilla != nullptr)
                        {
                            casilla->color_casilla = ROJO;
                            casilla->selecionada = true; // Casilla vacía
                            retorno = true;
                        }
                    }
                }

                // Mover hacia la izquierda
                for (int i = col - 1; i >= 0; --i)
                {
                    Casilla* casilla = tablero->get_casilla(i, fil);
                    if (casilla != nullptr && casilla->ocupado())
                    {

                        if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
                        {
                            casilla->color_casilla = ROJO;
                            casilla->selecionada = true; // Puede capturar la pieza enemiga
                            retorno = true;
                        }
                        break; // Detenerse al encontrar una pieza
                    }
                    else {
                        if (casilla != nullptr) {
                            casilla->color_casilla = ROJO;
                            casilla->selecionada = true; // Casilla vacía
                            retorno = true;
                        }
                    }
                }

                // Mover hacia arriba
                for (int i = fil + 1; i < 8; ++i)
                {

                    Casilla* casilla = tablero->get_casilla(col, i);
                    if (casilla != nullptr && casilla->ocupado())
                    {

                        if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
                        {
                            casilla->color_casilla = ROJO;
                            casilla->selecionada = true; // Puede capturar la pieza enemiga
                        }
                        break; // Detenerse al encontrar una pieza
                    }
                    else {
                        if (casilla != nullptr) {
                            casilla->color_casilla = ROJO;
                            casilla->selecionada = true; // Casilla vacía
                            retorno = true;
                        }
                    }
                }

                // Mover hacia abajo
                for (int i = fil - 1; i >= 0; --i)
                {
                    Casilla* casilla = tablero->get_casilla(col, i);
                    if (casilla != nullptr && casilla->ocupado())
                    {
                        if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
                        {
                            casilla->color_casilla = ROJO;
                            casilla->selecionada = true; // Puede capturar la pieza enemiga
                        }
                        break; // Detenerse al encontrar una pieza
                    }
                    else {
                        if (casilla != nullptr) {
                            casilla->color_casilla = ROJO;
                            casilla->selecionada = true; // Casilla vacía
                            retorno = true;
                        }
                    }
                }

                return retorno;

            }
        }
    

   
}


void Torre::mover(Tablero* tablero, int posx, int posy, int cvx, int cvy) {

    if (color_pieza == BLANCO) {

        tablero->asignar(posx, posy, new Torre(BLANCO));

        if (posx != cvy || posy != cvx) {

            tablero->contador++;


        }
    }

    else if (color_pieza == NEGRO) {

        tablero->asignar(posx, posy, new Torre(NEGRO));
        if (posx != cvy || posy != cvx) {

            tablero->contador++;


        }
    }


    if (posx != cvy || posy != cvx) {

        tablero->asignar(cvy, cvx, new CasillaVacia(BLANCO));


    }


}