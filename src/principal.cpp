#include <iostream>
#include "Tablero.h"


int main()
{

    Tablero tablero(SC);
    tablero.print();
    tablero.fmove({ 3,3 }, { 3,5 });
    tablero.print();
    
    tablero.seleccionar(tablero.premove({ 1,6 }));

    tablero.print();
}