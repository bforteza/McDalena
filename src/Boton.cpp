#include "Boton.h"
#include"iostream"
void Boton::dibuja()
{
	if (dibujado != nullptr)
		dibujado->draw();
}
void Boton::PlaySonido(int caso)
{
	if (mute == false)
	{
		if (caso == 1) ETSIDI::play("sonidos/claves.mp3");
		if (caso == 2) ETSIDI::play("sonidos/volver.mp3");
		if (caso == 3) ETSIDI::play("sonidos/reinicio.mp3");
		if (caso == 4) ETSIDI::play("sonidos/panda.mp3");
		if (caso == 5) ETSIDI::play("sonidos/mute.mp3");
		if (caso == 6) ETSIDI::play("sonidos/save.mp3");
		if (caso == 7) ETSIDI::play("sonidos/palos.mp3");
		if (caso == 8) ETSIDI::play("sonidos/mate.mp3");
		if (caso == 9) ETSIDI::play("sonidos/Respiracion.mp3");
	}
}
void Boton::detectar(GLdouble rx, GLdouble ry)
{
	if ((rx) > (x - Ancho / 2) && rx < (x + Ancho / 2) &&
		(ry) >(y - Alto / 2) && ry < (y + Alto / 2))
		dibujado = &sprite2;
	else {
		dibujado = &sprite;
	}
}


void Boton::click(GLdouble rx, GLdouble ry)
{
	if ((rx) > (x - Ancho / 2) && rx < (x + Ancho / 2) &&
		(ry) >(y - Alto / 2) && ry < (y + Alto / 2))
	{
		if (function != nullptr)
		{
			function();
			PlaySonido(Caso_sonido);
		}

	}

}




Boton::Boton(const GLdouble& Ancho, const GLdouble& Alto,
	const GLdouble& x, const GLdouble& y,
	std::string Path1, std::string Path2, int caso_sonido,
	std::function<void()> func)
	: Ancho(Ancho), Alto(Alto), x(x), y(y), sprite(ETSIDI::Sprite(Path1.c_str(), x, y, Ancho, Alto)),
	sprite2(ETSIDI::Sprite(Path2.c_str(), x, y, Ancho, Alto)), dibujado(nullptr), function(func), Caso_sonido(caso_sonido)
{

}
