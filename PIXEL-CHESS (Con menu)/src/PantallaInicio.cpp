#include "PantallaInicio.h"
#include <iostream>
#include "Menu.h"
void PantallaInicio::dibuja()
{
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,
		ETSIDI::getTexture("imagenes/Fondo2.png").id);
	glEnable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(-5.0, 5.0, -0.5);
	glTexCoord2d(1, 1); glVertex3d(5.0, 5.0, -0.5);
	glTexCoord2d(1, 0); glVertex3d(5.0, -5.0, -0.5);
	glTexCoord2d(0, 0); glVertex3d(-5.0, -5.0, -0.5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	ETSIDI::setTextColor(Color_UnPeon[0], Color_UnPeon[1], Color_UnPeon[2]);
	ETSIDI::setFont("fuentes/Pixel.ttf", T_UnPeon);
	ETSIDI::printxy("  4x5 Con  Un  Peon ", -2, 1);

	ETSIDI::setTextColor(Color_Speed[0], Color_Speed[1], Color_Speed[2]);
	ETSIDI::setFont("fuentes/Pixel.ttf", T_Speed);
	ETSIDI::printxy("      Speed Chess", -2, 0);

	ETSIDI::setTextColor(Color_Musica[0], Color_Musica[1], Color_Musica[2]);
	ETSIDI::setFont("fuentes/Pixel.ttf", T_Musica);
	ETSIDI::printxy("  Musica", -1, -1);

	ETSIDI::setTextColor(Color_Salir[0], Color_Salir[1], Color_Salir[2]);
	ETSIDI::setFont("fuentes/Pixel.ttf", T_Salir);
	ETSIDI::printxy("    Salir", -1, -2);
	pixelchess.draw();
}
void PantallaInicio::clicar(int x, int y,int &estado)
{
	if ((x > 254) && (x < 640))
	{
		if ((y > 207) && (y < 260))
		{
			estado = 1;
			ETSIDI::playMusica("sonidos/claves.mp3", true);
			ETSIDI::playMusica("sonidos/claves.mp3", false);
		}
	}
	if ((x > 306) && (x < 581))
	{
		if ((y > 313) && (y < 351))
		{
			estado = 2;
			ETSIDI::playMusica("sonidos/claves.mp3", true);
			ETSIDI::playMusica("sonidos/claves.mp3", false);
		}
	}
	if ((x > 365) && (x < 517))
	{
		if ((y > 408) && (y < 447))
		{
			estado = 3;
			ETSIDI::playMusica("sonidos/claves.mp3", true);
			ETSIDI::playMusica("sonidos/claves.mp3", false);
		}
	}
	if ((x > 393) && (x < 489))
	{
		if ((y > 489) && (y < 543))
		{
			ETSIDI::playMusica("sonidos/claves.mp3", true);
			ETSIDI::playMusica("sonidos/claves.mp3", false);
		}
	}
}
void PantallaInicio::detectar(int x, int y)
{
	if ((x >254) && (x <640))
	{
		if ((y > 207) && (y < 260))
		{
			Color_UnPeon[0] = 1;
			Color_UnPeon[1] = 1;
			Color_UnPeon[2] = 1;
			T_UnPeon = 49;
		}
		else
		{
			Color_UnPeon[0] = 0;
			Color_UnPeon[1] = 0;
			Color_UnPeon[2] = 0;
			T_UnPeon = 48;
		}
		}
	else
	{
		Color_UnPeon[0] = 0;
		Color_UnPeon[1] = 0;
		Color_UnPeon[2] = 0;
		T_UnPeon = 48;
	}

	if ((x > 306) && (x < 581))
	{
		if ((y > 313) && (y < 351))
		{
			Color_Speed[0] = 1;
			Color_Speed[1] = 1;
			Color_Speed[2] = 1;
			T_Speed = 49;
		}
		else
		{
			Color_Speed[0] = 0;
			Color_Speed[1] = 0;
			Color_Speed[2] = 0;
			T_Speed = 48;
		}
	}
	else
	{
		Color_Speed[0] = 0;
		Color_Speed[1] = 0;
		Color_Speed[2] = 0;
		T_Speed = 48;
	}
	if ((x > 365) && (x < 517))
	{
		if ((y > 408) && (y < 447))
		{
			Color_Musica[0] = 1;
			Color_Musica[1] = 1;
			Color_Musica[2] = 1;
			T_Musica = 49;
		}
		else
		{
			Color_Musica[0] = 0;
			Color_Musica[1] = 0;
			Color_Musica[2] = 0;
			T_Musica = 48;
		}
	}
	else
	{
		Color_Musica[0] = 0;
		Color_Musica[1] = 0;
		Color_Musica[2] = 0;
		T_Musica = 48;
	}

	if ((x > 393) && (x < 489))
	{
		if ((y > 489) && (y < 543))
		{
			Color_Salir[0] = 1;
			Color_Salir[1] = 1;
			Color_Salir[2] = 1;
			T_Salir = 49;
		}
		else
		{
			Color_Salir[0] = 0;
			Color_Salir[1] = 0;
			Color_Salir[2] = 0;
			T_Salir = 48;
		}
	}
	else
	{
		Color_Salir[0] = 0;
		Color_Salir[1] = 0;
		Color_Salir[2] = 0;
		T_Salir = 48;
	}
}