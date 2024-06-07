#include "boton.h"
#pragma once
class BotonEnclavado:public Boton
{
	bool marca_enclavamiento = 0;
	ETSIDI::Sprite sprite3;
	std::function<void()> function2;
public:

	void dibuja();
	void detectar(GLdouble rx, GLdouble ry);
	void click(GLdouble rx, GLdouble ry);

	BotonEnclavado(const GLdouble& Ancho, const GLdouble& Alto,
		const GLdouble& x, const GLdouble& y,
		std::string Path1, std::string Path2, std::string Path3,
		std::function<void()> func, std::function<void()> func2);
};

