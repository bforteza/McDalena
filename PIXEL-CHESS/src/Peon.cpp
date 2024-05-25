#include "Peon.h"
using ETSIDI::Sprite;

void Peon::dibuja(Vector2D coordenadas, char equipo)
{
	if (equipo == 'n')
	{
		glPushMatrix();
		glTranslated(coordenadas.x - 0.84, (-1)*coordenadas.y * 0.98 + 1.8, 0.9);
		glScalef(1, 1, 1);
		sprite->draw();
	}
	if (equipo == 'b')
	{
		glPushMatrix();
		glTranslated(coordenadas.x - 4.10, (-1)*coordenadas.y * 0.98+ 3.95 , 0.9);
		glScalef(1, 1, 1);
		sprite->draw();
	}
	
}
