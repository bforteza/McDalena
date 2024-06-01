#include <iostream>
#include "Tablero.h"


int main()
{

    Tablero tablero(SC);
    VectorCoordenadas premoves = tablero.premove({ B,5 });
    tablero.seleccionar(premoves);
    tablero.print();
    
}