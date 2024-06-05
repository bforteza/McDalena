// Ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <freeglut.h>
#include <ETSIDI.h>
#include "Tablero.h"
#include <vector>
#include "Ventana.h"
#include "Boton.h"
#include "VentanaTablero.h"
#pragma once


Tablero tablero(UP);

VentanaTablero  prueba(700, 700, "bin/imagenes/Fondo.png",UP);

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int boton, int state, int x, int y);
void MouseMove(int x, int y);
int x_raton, y_raton;
bool click;


int main(int argc, char* argv[])
{

	
   //Inicializar el gestor de ventanas FREEGLUT
//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("MiJuego");
	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	gluPerspective(90.0, 800/800.0f, 400, 500);
	glEnable(0x0B57);
	glMatrixMode(GL_PROJECTION);


	
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);
	glutPassiveMotionFunc(MouseMove);
	glutMainLoop();

	return 0;
}


void OnDraw(void)
{
	
	
	prueba.dibuja();
	//tablero.dibuja();
	glutSwapBuffers();
}

void OnTimer(int value)
{

	
	
	prueba.detecta(x_raton, y_raton);
	if (click) {
		prueba.click(x_raton, y_raton);
		//tablero.clicar(x_raton, y_raton);
	}

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();

}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	if (key == 'e')
	{

	}

	glutPostRedisplay();

}
void OnMouseClick(int boton, int state, int x, int y)
{
	if (boton == GLUT_LEFT && state == GLUT_DOWN)
	{
		click = true;
		std::cout << x << " " << y << "\n";
	}
	if (boton == GLUT_LEFT && state == GLUT_UP)
	{
		click = false;
	}
}
void MouseMove(int x, int y)
{
	x_raton = x;
	y_raton = y;
	
}