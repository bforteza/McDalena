#pragma once
#include "freeglut.h"
#include <string>
#include <functional>
#include "ETSIDI.h"
class Boton
{
protected:
	GLdouble Ancho;
	GLdouble Alto;
	GLdouble x;
	GLdouble y;
	ETSIDI::Sprite* dibujado;
	ETSIDI::Sprite sprite;
	ETSIDI::Sprite sprite2;

	std::function<void()> function;
public:
	 virtual void dibuja();
	 virtual void detectar(GLdouble rx, GLdouble ry);
	 virtual void click(GLdouble rx, GLdouble ry);
	Boton(const GLdouble& Ancho, const GLdouble& Alto, 
		const GLdouble& x, const GLdouble& y,
		std::string Path1,std::string Path2 ,
		std::function<void()> func);

};

