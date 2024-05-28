#include "Torre.h"
#include "Tablero.h"
#include <iostream>

void Torre::print() {

	std::cout << ((color_pieza == NEGRO) ? "R" : "r");
}

bool Torre::premove(Tablero* tablero, int col, int fil) {
    // Mover hacia la derecha
    for (int i = col + 1; i < 8; ++i) 
    {
        Casilla* casilla = tablero->get_casilla(i, fil);
        if (casilla != nullptr && casilla->ocupado()) 
	{
            if (dynamic_cast<Pieza*>(casilla)->get_color_pieza() != color_pieza)
	    {
                casilla->selecionada = true; // Puede capturar la pieza enemiga
            }
            break; // Detenerse al encontrar una pieza
        }
        else {
            if (casilla != nullptr) 
	    {
                casilla->selecionada = true; // Casilla vacía
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
                casilla->selecionada = true; // Puede capturar la pieza enemiga
            }
            break; // Detenerse al encontrar una pieza
        }
        else {
            if (casilla != nullptr) {
                casilla->selecionada = true; // Casilla vacía
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
                casilla->selecionada = true; // Puede capturar la pieza enemiga
            }
            break; // Detenerse al encontrar una pieza
        }
        else {
            if (casilla != nullptr) {
                casilla->selecionada = true; // Casilla vacía
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
                casilla->selecionada = true; // Puede capturar la pieza enemiga
            }
            break; // Detenerse al encontrar una pieza
        }
        else {
            if (casilla != nullptr) {
                casilla->selecionada = true; // Casilla vacía
            }
        }
    }

    return true;
}
