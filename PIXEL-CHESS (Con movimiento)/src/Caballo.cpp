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
			sprite_pieza = new Sprite("imagenes/CaballoN.png", 1.66 + origenx + fil * 1.072 - 1.60, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);
		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoB.png", 1.66 + origenx + fil * 1.072 - 1.60, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	if (color_casilla == BLANCO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoN.png", 1.66 + origenx + fil * 1.072 - 1.60, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoB.png", 1.66 + origenx + fil * 1.072 - 1.60, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

		}
	}
	if (color_casilla == VERDE)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoN.png", 1.66 + origenx + fil * 1.072 - 1.60, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoB.png", 1.66 + origenx + fil * 1.072 - 1.60, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
	}
	if (color_casilla == ROJO)
	{
		if (color_pieza == NEGRO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

		}
		if (color_pieza == BLANCO)
		{
			sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
			sprite_pieza = new Sprite("imagenes/CaballoB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

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
				casilla->color_casilla = ROJO;
                casilla->selecionada = true;
                retorno = true;
            }
        }
    }

    return true;
}


void Caballo::mover(Tablero* tablero, int posx, int posy, int cvx, int cvy) {

	if (color_pieza == BLANCO) {

		tablero->asignar(posx, posy, new Caballo(BLANCO));
	}

	else if (color_pieza == NEGRO) {

		tablero->asignar(posx, posy, new Caballo(NEGRO));
	}


	if (posx != cvy || posy != cvx) {

		tablero->asignar(cvy, cvx, new CasillaVacia(BLANCO));
	}







}