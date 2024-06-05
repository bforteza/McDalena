#include "Boton.h"
#include "iostream"
using ETSIDI::Sprite;
void Boton::dibuja()
{
	if (BotonPulsado == false)
	{
		dibujado = &sprite;
		dibujado->draw();
	}
	if (BotonPulsado == true)
	{
		dibujado = &sprite2;
		dibujado->draw();
	}
	
}

void Boton::detectar(GLdouble rx, GLdouble ry)
{
	if ((rx) > (x - Ancho / 2) && rx < (x + Ancho / 2) &&
		(ry) >(y - Alto / 2) && ry < (y + Alto / 2))
		BotonPulsado = true;
	else {
		BotonPulsado = false;
	}
	
}


void Boton::click(GLdouble rx, GLdouble ry,int &estado)
{
	if ((rx) > (x - Ancho / 2) && rx < (x + Ancho / 2) &&
		(ry) >(y - Alto / 2) && ry < (y + Alto / 2))
	{
		estado = botoncambiaestado;
	}
	
}




Boton::Boton(const GLdouble& Ancho, const GLdouble& Alto,
	const GLdouble& x, const GLdouble& y,
	std::string Path1, std::string Path2,const int cestado)
	: Ancho(Ancho), Alto(Alto), x(x), y(y) , sprite( ETSIDI::Sprite(Path1.c_str(),x,y,Ancho,Alto)),
		sprite2(ETSIDI::Sprite(Path2.c_str() , x, y, Ancho, Alto)), dibujado(nullptr), BotonPulsado(0)
	,botoncambiaestado(cestado)
{
	
}
