#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include <string>

class Ventana
{
	GLdouble Ancho;
	GLdouble Alto;
	std::string texturePath ;
public:

	void dibuja();

	Ventana(const GLdouble& Ancho, const GLdouble& Alto, std::string Path);
	
};

