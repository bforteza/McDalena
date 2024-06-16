#include "Animacion.h"
#include "iostream"
void Animacion::dibuja()
{
	glPushMatrix();
	glTranslated(1, 1, 1);

	secuencia.draw();

	glPopMatrix();
}
void Animacion::anima()
{
	glPushMatrix();
	glTranslated(1, 1, 1);

	secuencia.loop();

	glPopMatrix();
}
