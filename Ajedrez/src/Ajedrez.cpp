// Ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "Tablero.h"
#include <vector>
using std::vector;

bool pgn = 0;

int main()
{
   
    Tablero tablero(UP);
   
    tablero.premove(C, 1);
    tablero.print();

    if (tablero.ahogado(BLANCO)) {
        std::cout << "ahogado";
    }
    if (tablero.jaque(NEGRO)) {
        std::cout << "JAQUE";
    }
    if (tablero.mate(NEGRO)) {
        std::cout << "MATE";
    }



   // bool b = tablero.jaque(NEGRO);



      //  std::cout << "jaque";
   
   // tablero.get_casilla(D, 0)->print();
   
}

void PGN(Tablero& tab,Juego mod) //Para modificar el tablero actual lo paso como referencia
{
    if (pgn) 
    {
        Tablero::Tablero(mod);
        tab.print();
        vector<Casilla*> movs = tab.get_mov();
        for (int i = 0; i < movs.size(); i++) //Recorro las posiciones guardadas 
        {
            Pieza* pieza = dynamic_cast<Pieza*>(movs[i]);
            Pieza* pieza2 = dynamic_cast<Pieza*>(movs[i + 1]);
            if (pieza == nullptr || pieza2 == nullptr) {
                continue; // Por seguridad, por si alguna conversión falla, continúa con el siguiente movimiento
            }
            Color aux = movs[i]->get_color_casilla();
            Color aux2 = movs[i + 1]->get_color_casilla();

            //Con este bucle itero sobre todo el tablero
            for (int f = 0; f < tab.cuadricula.size(); f++) {
                for (int c = 0; c < tab.cuadricula[f].size(); c++) {
                    Casilla*& casilla = tab.get_casilla(c, f);

                    if (casilla == movs[i]) {
                        delete casilla;
                        casilla = new CasillaVacia(aux);
                    }
                    else if (casilla == movs[i + 1]) {
                        pieza2->set_color_casilla(aux2);
                        tab.asignar(c, f, pieza2);
                    }
                }
            }
        }
    }
    
}
