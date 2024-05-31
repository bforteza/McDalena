#include <iostream>
#include "Caballo.h"
#include "Tablero.h"

void Caballo::print(int col, int fil, double origenx, double origeny) {

	//std::cout << ((color_pieza == NEGRO) ? "N" : "n");
	if (color_casilla == NEGRO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoN.png", fil * 1.072 - 1.60, -1.072 * col + 2.45, 0.8, 0.8);
		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoB.png", fil * 1.072 - 1.60, -1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	if (color_casilla == BLANCO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoN.png", fil * 1.072 - 1.60, -1.072 * col + 2.45, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoB.png", fil * 1.072 - 1.60, -1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	sprite_pieza->draw();
	sprite_casilla->draw();

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
