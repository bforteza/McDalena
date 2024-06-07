#include "CasillaVacia.h"
#include <iostream>


void CasillaVacia::set_verde()
{
	sprite_casilla = &casilla_verde;
}

void CasillaVacia::set_selecionado() {
	sprite_casilla = &casilla_seleccionada;
}

void CasillaVacia::print(const float x, const float y) {

	if (sprite_casilla == nullptr)
		sprite_casilla = &casilla;
	glTranslated(x, y, 0);
	sprite_casilla->draw();
	glTranslated(-x, -y, 0);
	sprite_casilla = &casilla;

}
