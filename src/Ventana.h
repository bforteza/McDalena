#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include <string>
#include "vector"
#include "Boton.h"
class Ventana
{
protected:
	GLdouble tx, ty;
	GLdouble Ancho;
	GLdouble Alto;
	std::string texturePath;
	std::vector<Boton> botones;
	
public:

	virtual void dibuja() ;
	virtual void detecta(GLdouble x, GLdouble y);
	virtual void click();
	Ventana(const GLdouble& Ancho, const GLdouble& Alto, std::string Path);
	void add_boton(Boton entrada);
	//ejemplo
	//prueba.add_boton(Boton(100, 100, -350, 350, "bin/imagenes/Volver.png", "bin/imagenes/PreVolver.png"));
};

