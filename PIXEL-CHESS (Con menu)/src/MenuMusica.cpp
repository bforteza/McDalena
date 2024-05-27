#include "MenuMusica.h"
#include <iostream>
#include "Menu.h"


void MenuMusica::dibuja()
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

	mute.draw();
	titulomusica.draw();
	papel.draw();
	volver.draw();
	

	ETSIDI::setTextColor(Color_LeapOfFaith[0], Color_LeapOfFaith[1], Color_LeapOfFaith[2]);
	ETSIDI::setFont("fuentes/Pixel.ttf", T_LeapOfFaith);
	ETSIDI::printxy("      Leap Of Faith ", -2, 1);

	ETSIDI::setTextColor(Color_LiveFreeOrDie[0], Color_LiveFreeOrDie[1], Color_LiveFreeOrDie[2]);
	ETSIDI::setFont("fuentes/Pixel.ttf", T_LiveFreeOrDie);
	ETSIDI::printxy("    Live Free Or Die ", -2, 0);

	ETSIDI::setTextColor(Color_Butterflies[0], Color_Butterflies[1], Color_Butterflies[2]);
	ETSIDI::setFont("fuentes/Pixel.ttf", T_Butterflies);
	ETSIDI::printxy("		       Butterflies ", -2, -2);
	ETSIDI::setTextColor(Color_Butterflies[0], Color_Butterflies[1], Color_Butterflies[2]);
	ETSIDI::setFont("fuentes/Pixel.ttf", T_Butterflies);
	ETSIDI::printxy("		        (Calmado) ", -2, -1);
}

void MenuMusica::detectar(int x, int y)
{
	if ((x > 254) && (x < 640))
	{
		if ((y > 207) && (y < 260))
		{
			Color_LeapOfFaith[0] = 0;
			Color_LeapOfFaith[1] = 1;
			Color_LeapOfFaith[2] = 1;
			T_LeapOfFaith = 49;
		}
		else
		{
			Color_LeapOfFaith[0] = 0;
			Color_LeapOfFaith[1] = 0;
			Color_LeapOfFaith[2] = 0;
			T_LeapOfFaith = 48;
		}
	}
	else
	{
		Color_LeapOfFaith[0] = 0;
		Color_LeapOfFaith[1] = 0;
		Color_LeapOfFaith[2] = 0;
		T_LeapOfFaith = 48;
	}
	if ((x > 306) && (x < 581))
	{
		if ((y > 313) && (y < 351))
		{
			Color_LiveFreeOrDie[0] = 0;
			Color_LiveFreeOrDie[1] = 1;
			Color_LiveFreeOrDie[2] = 1;
			T_LiveFreeOrDie = 49;
		}
		else
		{
			Color_LiveFreeOrDie[0] = 0;
			Color_LiveFreeOrDie[1] = 0;
			Color_LiveFreeOrDie[2] = 0;
			T_LiveFreeOrDie = 48;
		}
	}
	else
	{
		Color_LiveFreeOrDie[0] = 0;
		Color_LiveFreeOrDie[1] = 0;
		Color_LiveFreeOrDie[2] = 0;
		T_LiveFreeOrDie = 48;
	}

	if ((x > 393) && (x < 489))
	{
		if ((y > 489) && (y < 543))
		{
			Color_Butterflies[0] = 0;
			Color_Butterflies[1] = 1;
			Color_Butterflies[2] = 1;
			T_Butterflies = 49;
		}
		else
		{
			Color_Butterflies[0] = 0;
			Color_Butterflies[1] = 0;
			Color_Butterflies[2] = 0;
			T_Butterflies = 48;
		}
	}
	else
	{
		Color_Butterflies[0] = 0;
		Color_Butterflies[1] = 0;
		Color_Butterflies[2] = 0;
		T_Butterflies = 48;
	}

	if ((x > 97) && (x < 153))
	{
		if ((y > 39) && (y < 83))
		{
			volver = { "imagenes/Volver.png", -3,3,1, 1 };
		}
		else
		{
			volver = { "imagenes/PreVolver.png", -3,3,1, 1 };
		}
	}
	else
	{
		volver = { "imagenes/PreVolver.png", -3,3,1, 1 };
	}
}

void MenuMusica::clicar(int x, int y,int& estado, int &muteado)
{
	if ((x > 254) && (x < 640))
	{
		if ((y > 207) && (y < 260))
		{
			Color_LeapOfFaith[0] = 0;
			Color_LeapOfFaith[1] = 0;
			Color_LeapOfFaith[2] = 1;
			T_LeapOfFaith = 49;
			ETSIDI::playMusica("sonidos/LeapOfFaith.mp3", true);
		}
		else
		{
			Color_LeapOfFaith[0] = 0;
			Color_LeapOfFaith[1] = 0;
			Color_LeapOfFaith[2] = 0;
			T_LeapOfFaith = 48;
		}
	}
	else
	{
		Color_LeapOfFaith[0] = 0;
		Color_LeapOfFaith[1] = 0;
		Color_LeapOfFaith[2] = 0;
		T_LeapOfFaith = 48;
	}
	if ((x > 306) && (x < 581))
	{
		if ((y > 313) && (y < 351))
		{
			Color_LiveFreeOrDie[0] = 0;
			Color_LiveFreeOrDie[1] = 0;
			Color_LiveFreeOrDie[2] = 1;
			T_LiveFreeOrDie = 49;
			ETSIDI::playMusica("sonidos/LiveFreeOrDie.mp3", true);
		}
		else
		{
			Color_LiveFreeOrDie[0] = 0;
			Color_LiveFreeOrDie[1] = 0;
			Color_LiveFreeOrDie[2] = 0;
			T_LiveFreeOrDie = 48;
		}
	}
	else
	{
		Color_LiveFreeOrDie[0] = 0;
		Color_LiveFreeOrDie[1] = 0;
		Color_LiveFreeOrDie[2] = 0;
		T_LiveFreeOrDie = 48;
	}

	if ((x > 393) && (x < 489))
	{
		if ((y > 489) && (y < 543))
		{
			ETSIDI::playMusica("sonidos/Butterflies.mp3", true);
			Color_Butterflies[0] = 0;
			Color_Butterflies[1] = 0;
			Color_Butterflies[2] = 1;
			T_Butterflies = 49;
			
		}
		else
		{
			Color_Butterflies[0] = 0;
			Color_Butterflies[1] = 0;
			Color_Butterflies[2] = 0;
			T_Butterflies = 48;
		}
	}
	else
	{
		Color_Butterflies[0] = 0;
		Color_Butterflies[1] = 0;
		Color_Butterflies[2] = 0;
		T_Butterflies = 48;
	}
	if ((x > 748) && (x < 819))
	{
		if (((y > 34) && (y < 89)))
		{
			muteado++;
		}
		if (muteado %2==0)
		{
			mute = { "imagenes/Mute.png", 3,3,1, 1 };
			ETSIDI::stopMusica();
		}
		else
		{
			mute = { "imagenes/NoMute.png", 3,3,1, 1 };
		}
	}
	if ((x > 97) && (x < 153))
	{
		if ((y > 39) && (y < 83))
		{
			estado = 0;
		}
	}
	}