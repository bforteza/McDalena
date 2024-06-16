#pragma once
#include "ETSIDI.h"

using ETSIDI::Sprite;
class PiezaGrafica
{
protected:
	Sprite* sprite_pieza{}; //Sprite Correspondiente
	double lado = 150;
public:
	void print(const GLdouble x, const GLdouble y) {
		glTranslated(x, y, 0);
		sprite_pieza->draw();
		glTranslated(-x, -y, 0);
	};
	void set_size(float _lado) {
		sprite_pieza->setSize(_lado, _lado);
		sprite_pieza->setCenter(_lado / 2, _lado / 2);
		lado = _lado;
	}
};

