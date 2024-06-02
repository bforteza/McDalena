#include <iostream>
#include "Tablero.h"


int main()
{

    Tablero tablero(SC);
    tablero.print();
    //tablero.seleccionar(tablero.premove({ 1,6 }));
    //tablero.print();
   if( tablero.jaque(BLANCO))
       std::cout << "JAQUE";
   if (tablero.ahogado(NEGRO))
       std::cout << "AHOGADO";
   if (tablero.mate(BLANCO))
       std::cout << "MATE";
}