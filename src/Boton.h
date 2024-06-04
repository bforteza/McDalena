#pragma once
#include "freeglut.h"
#include <string>
#include "ETSIDI.h"
class Boton
{
	GLdouble Ancho;
	GLdouble Alto;
	GLdouble x;
	GLdouble y;

	ETSIDI::Sprite sprite;
public:
	void dibuja();
	
	Boton(const GLdouble& Ancho, const GLdouble& Alto, const GLdouble& x, const GLdouble& y,std::string Path);
};

