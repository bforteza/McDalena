#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include <string>
#include "vector"
#include "Boton.h"
class Ventana
{
	GLdouble Ancho;
	GLdouble Alto;
	std::string texturePath;
	std::vector<Boton> botones;
	
public:

	void dibuja();
	void detecta();
	void click();
	Ventana(const GLdouble& Ancho, const GLdouble& Alto, std::string Path);
	
};

