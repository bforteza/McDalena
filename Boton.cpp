#include "Boton.h"

void Boton::dibuja()
{

	sprite.draw();
	
}





Boton::Boton(const GLdouble& Ancho, const GLdouble& Alto, const GLdouble& x, const GLdouble& y,std::string path)
	: Ancho(Ancho), Alto(Alto), x(x), y(y) , sprite( ETSIDI::Sprite(path.c_str(),x,y,Ancho,Alto))
{

}
