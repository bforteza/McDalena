#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include <string>
#include "vector"
#include "Boton.h"
#include "BotonEnclavado.h"
#include "Animacion.h"
#include "AnimacionMovil.h"
class Ventana
{
protected:
	GLdouble tx, ty;
	GLdouble Ancho;
	GLdouble Alto;
	std::string texturePath;
	std::vector<Boton*> botones;
	std::vector<Animacion*> animaciones;
	int mute;

public:


	virtual void dibuja();
	virtual void detecta(GLdouble x, GLdouble y);
	virtual void click();
	Ventana(const GLdouble& Ancho, const GLdouble& Alto, std::string Path);
	void add_boton(Boton* entrada);
	void add_animacion(Animacion* animacion);
	void eliminar_boton();
	void eliminar_animacion();
	void anima();
	void mutear();
	void set_mute(int _mute) { mute = _mute; }
};

