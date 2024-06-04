#include "Ventana.h"

void Ventana::dibuja()
{
	//gluPerspective(90.0, 800 / 800.0f, 400, 500);
	gluPerspective(90.0, Ancho / Alto, (Ancho/2) * 0.8, (Ancho/2) * 1.2);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, Ancho/2, // posicion del ojo
		0.0, 0, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 




	glDisable(GL_LIGHTING);
	
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(texturePath.c_str()   ).id);
	

	glBegin(GL_POLYGON);

	glTexCoord2d(0, 1); glVertex3d(-Ancho/2  , Alto/2, 0);
	glTexCoord2d(1, 1); glVertex3d(Ancho / 2 , Alto/2, 0);
	glTexCoord2d(1, 0); glVertex3d(Ancho / 2 , -Alto/2, 0);
	glTexCoord2d(0, 0); glVertex3d(-Ancho / 2, -Alto/2, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	glPushMatrix();


	glPopMatrix();


}


Ventana::Ventana(const GLdouble& Ancho, const GLdouble& Alto,std::string Path)
	: Ancho(Ancho), Alto(Alto), texturePath(Path)
{
}
