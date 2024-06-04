#include "Boton.h"

void Boton::dibuja()
{
	if(dibujado!= nullptr)
	dibujado->draw();
}

void Boton::detectar(GLdouble rx, GLdouble ry)
{
	if ((rx) > (x - Ancho/2) && rx < (x + Ancho/2) &&
		(ry) > (y - Alto / 2) && ry < (y + Alto / 2))
		dibujado = &sprite2;
	else {
		dibujado = &sprite;
	}
}





Boton::Boton(const GLdouble& Ancho, const GLdouble& Alto, const GLdouble& x, const GLdouble& y,std::string Path1, std::string Path2)
	: Ancho(Ancho), Alto(Alto), x(x), y(y) , sprite( ETSIDI::Sprite(Path1.c_str(),x,y,Ancho,Alto)),
		sprite2(ETSIDI::Sprite(Path2.c_str() , x, y, Ancho, Alto)), dibujado(nullptr)
{
	
}
