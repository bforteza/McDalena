#include "Rey.h"
using ETSIDI::Sprite;

void Rey::dibuja(Vector2D coordenadas, Color equipo)
{
	if (equipo == NEGRO)
	{
		glPushMatrix();
		glTranslated(coordenadas.x*0.98 - 0.84, (-1) * coordenadas.y * 0.98 + 1.8, 0.9);
		glScalef(1, 1, 1);
		sprite->draw();
	}
	if (equipo == BLANCO)
	{
		glPushMatrix();
		glTranslated(coordenadas.x*0.98 - 4.10, (-1) * coordenadas.y * 0.98 + 3.95, 0.9);
		glScalef(1, 1, 1);
		sprite->draw();
	}

}