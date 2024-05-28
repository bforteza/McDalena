#include <iostream>
#include "Caballo.h"
#include "Tablero.h"

void Caballo::print() {

	std::cout << ((color_pieza == NEGRO) ? "N" : "n");
}

bool Caballo::premove(Tablero* tablero, int col, int fil) {
    bool retorno = false;
    // Array de posibles movimientos del caballo
    Casilla* movimientos[8] = {
        tablero->get_casilla(col - 2, fil - 1),
        tablero->get_casilla(col - 1, fil - 2),
        tablero->get_casilla(col + 1, fil - 2),
        tablero->get_casilla(col + 2, fil - 1),
        tablero->get_casilla(col + 2, fil + 1),
        tablero->get_casilla(col + 1, fil + 2),
        tablero->get_casilla(col - 1, fil + 2),
        tablero->get_casilla(col - 2, fil + 1)
    };

    // Recorro las posibles casillas de movimiento del caballo
    for (Casilla* casilla : movimientos) {
        if (casilla != nullptr) {
            // Verificar si hay una pieza en la casilla
            Pieza* pieza = dynamic_cast<Pieza*>(casilla);
            if (!casilla->ocupado() || (pieza != nullptr && pieza->get_color_pieza() != color_pieza)) {
                casilla->selecionada = true;
                retorno = true;
            }
        }
    }

    return true;
}
