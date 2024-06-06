#include "Coordinador.h"

void Coordinador::dibuja()
{
	if (actual != nullptr) {
		actual->dibuja();
	}
}

void Coordinador::detecta(GLdouble x, GLdouble y)
{
	if (actual != nullptr) {
		actual->detecta(x,y);
	}
}

void Coordinador::click()
{
	if (actual != nullptr) {
		actual->click();
	}
}

void Coordinador::set_speedchess()
{
	actual = &speedchess;
}

void Coordinador::set_unicopeon()
{
	actual = &unicopeon;
}

void Coordinador::set_menu()
{
	actual = &Menu;
}

Coordinador::Coordinador(GLdouble _ancho, GLdouble _alto) :
	ancho(_ancho), alto(_alto) {
	
	actual = &Menu;

	Menu.add_boton(Boton(300, 40, 0, 0, "bin/imagenes/UnpeonNegro.png", "bin/imagenes/UnpeonBlanco.png", std::bind(&Coordinador::set_unicopeon, this)));
	Menu.add_boton(Boton(200, 40, 0, -70, "bin/imagenes/speed.png", "bin/imagenes/speedrojo.png", std::bind(&Coordinador::set_speedchess, this)));
	Menu.add_boton(Boton(700, 90, 0, 140, "bin/imagenes/pixelchess.png", "bin/imagenes/pixelchess.png", nullptr));

	speedchess.add_boton(Boton(100, 100, -300, 300, "bin/imagenes/Volver.png", "bin/imagenes/PreVolver.png", std::bind(&Coordinador::set_menu, this)));
	unicopeon.add_boton(Boton(100, 100, -300, 300, "bin/imagenes/Volver.png", "bin/imagenes/PreVolver.png", std::bind(&Coordinador::set_menu, this)));
}