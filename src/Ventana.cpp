#include "Ventana.h"

void Ventana::dibuja()
{

	gluPerspective(90.0, Ancho / Alto, (Alto / 2) * 0.8, (Alto / 2) * 1.2);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, Alto / 2,
		0.0, 0, 0.0,
		0.0, 1.0, 0.0);




	glDisable(GL_LIGHTING);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(texturePath.c_str()).id);


	glBegin(GL_POLYGON);

	glTexCoord2d(0, 1); glVertex3d(-Ancho / 2, Alto / 2, 0);
	glTexCoord2d(1, 1); glVertex3d(Ancho / 2, Alto / 2, 0);
	glTexCoord2d(1, 0); glVertex3d(Ancho / 2, -Alto / 2, 0);
	glTexCoord2d(0, 0); glVertex3d(-Ancho / 2, -Alto / 2, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	glPushMatrix();




	for (auto& iter : botones) {
		if (iter != nullptr)
			iter->dibuja();
	}

	for (auto& iter : animaciones) {
		if (iter != nullptr)
			iter->dibuja();
	}

	glPopMatrix();
}


Ventana::Ventana(const GLdouble& Ancho, const GLdouble& Alto, std::string Path)
	: Ancho(Ancho), Alto(Alto), texturePath(Path)
{

}

void Ventana::add_boton(Boton* entrada)
{
	botones.push_back(entrada);
}

void Ventana::eliminar_boton()
{
	if (botones.back() != nullptr)
		delete botones.back();
	botones.pop_back();
}


void Ventana::detecta(GLdouble x, GLdouble y) {
	tx = x - Ancho / 2;
	ty = Alto / 2 - y;

	for (auto& iter : botones) {
		iter->detectar(tx, ty);
	}
}

void Ventana::click() {


	for (auto& iter : botones) {
		if (iter != nullptr)
			iter->click(tx, ty);
	}

}

void Ventana::anima()
{
	for (auto& iter : animaciones) {
		if (iter != nullptr)
			iter->anima();
	}
}

void Ventana::add_animacion(Animacion* animacion)
{
	animaciones.push_back(animacion);
}

void Ventana::eliminar_animacion()
{
	if (animaciones.back() != nullptr)
		delete animaciones.back();
	animaciones.pop_back();
}

void Ventana::mutear() {


	for (auto& iter : botones) {
		if (iter != nullptr)
		{
			iter->set_mute(mute);
		}

	}

}