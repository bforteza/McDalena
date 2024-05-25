#include "Tablero.h"

void Tablero::dibuja()
{
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,
		ETSIDI::getTexture("imagenes/Fondo.png").id);
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


	for (int i=0; i < 5; i++)
	{
		for (int j=0; j < 4; j++)
		{
			casillas.at(i).at(j).dibuja();
		}
	}
	Peon1_Negro.dibuja(Peon1_Negro.coordenadas,Peon1_Negro.equipo);
	Peon1_Blanco.dibuja(Peon1_Blanco.coordenadas, Peon1_Blanco.equipo);
}
void Tablero::inicializa()
{


	casillas.push_back({ new Sprite("imagenes/cuadrado.png", -1.66, 2.50, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", -0.58, 2.50, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado.png", 0.5, 2.50, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", 1.58, 2.50, 1.2, 1.2) });

	casillas.push_back({ new Sprite("imagenes/cuadrado2.png", -1.66, 1.42, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado.png", -0.58, 1.42, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", 0.5, 1.42, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado.png", 1.58, 1.42, 1.2, 1.2) });

	casillas.push_back({ new Sprite("imagenes/cuadrado.png", -1.66, 0.34, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", -0.58, 0.34, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado.png", 0.5, 0.34, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", 1.58, 0.34, 1.2, 1.2) });

	casillas.push_back({ new Sprite("imagenes/cuadrado2.png", -1.66, -0.74, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado.png", -0.58, -0.74, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", 0.5, -0.74, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado.png", 1.58, -0.74, 1.2, 1.2) });

	casillas.push_back({ new Sprite("imagenes/cuadrado.png", -1.66, -1.82, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", -0.58,  -1.82, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado.png", 0.5, -1.82, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", 1.58, -1.82, 1.2, 1.2) });

	

}