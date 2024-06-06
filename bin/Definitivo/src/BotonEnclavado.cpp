#include "BotonEnclavado.h"
#include "iostream"
BotonEnclavado::BotonEnclavado(const GLdouble& Ancho, const GLdouble& Alto,
	const GLdouble& x, const GLdouble& y,
	std::string Path1, std::string Path2, std::string Path3,
	std::function<void()> func) :
	Boton::Boton(Ancho, Alto, x, y, Path1, Path2, func), sprite3(ETSIDI::Sprite(Path3.c_str(), x, y, Ancho, Alto))
{

}

void BotonEnclavado::dibuja()
{

	if (dibujado != nullptr)
		dibujado->draw();
}

void BotonEnclavado::detectar(GLdouble rx, GLdouble ry)
{
	if ((rx) > (x - Ancho / 2) && rx < (x + Ancho / 2) &&
		(ry) >(y - Alto / 2) && ry < (y + Alto / 2))
	{
		dibujado = &sprite2;
	}
		
	else {
		if (marca_enclavamiento == true)
	{
		dibujado = &sprite3;
	}
	if (marca_enclavamiento == false)
	{
		dibujado = &sprite;
	}
		}
}


void BotonEnclavado::click(GLdouble rx, GLdouble ry)
{
	
	if ((rx) > (x - Ancho / 2) && rx < (x + Ancho / 2) &&
		(ry) >(y - Alto / 2) && ry < (y + Alto / 2))
	{

			if (function != nullptr)
			{
				marca_enclavamiento=!marca_enclavamiento;
				function();
			}
		
	}	
}