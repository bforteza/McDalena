// Ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <freeglut.h>
#include <ETSIDI.h>
#include "Tablero.h"
#include <vector>
#include <Menu.h>
#pragma once
using std::vector;

bool pgn = 0;

Menu menu;
void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int boton, int state, int x, int y);
void MouseMove(int x, int y);

int main(int argc, char* argv[])
{

		//tablero.premove(C, 1);
		//tablero.print();
	/*
		if (tablero.ahogado(BLANCO)) {
			std::cout << "ahogado";
		}
		if (tablero.jaque(NEGRO)) {
			std::cout << "JAQUE";
		}
		if (tablero.mate(NEGRO)) {
			std::cout << "MATE";
		}
    */



   // bool b = tablero.jaque(NEGRO);



      //  std::cout << "jaque";
   
   // tablero.get_casilla(D, 0)->print();
   //Inicializar el gestor de ventanas FREEGLUT
//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(900, 900);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("MiJuego");
	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 700.0f, 0.1, 150);


	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);
	glutPassiveMotionFunc(MouseMove);
	glutMainLoop();

	return 0;
}

void PGN(Tablero& tab,Juego mod) //Para modificar el tablero actual lo paso como referencia
{
    if (pgn) 
    {
        Tablero::Tablero(mod);
        tab.print();
        vector<Casilla*> movs = tab.get_mov();
        for (int i = 0; i < movs.size(); i++) //Recorro las posiciones guardadas 
        {
            Pieza* pieza = dynamic_cast<Pieza*>(movs[i]);
            Pieza* pieza2 = dynamic_cast<Pieza*>(movs[i + 1]);
            if (pieza == nullptr || pieza2 == nullptr) {
                continue; // Por seguridad, por si alguna conversión falla, continúa con el siguiente movimiento
            }
            Color aux = movs[i]->get_color_casilla();
            Color aux2 = movs[i + 1]->get_color_casilla();

            //Con este bucle itero sobre todo el tablero
            for (int f = 0; f < tab.cuadricula.size(); f++) {
                for (int c = 0; c < tab.cuadricula[f].size(); c++) {
                    Casilla*& casilla = tab.get_casilla(c, f);

                    if (casilla == movs[i]) {
                        delete casilla;
                        casilla = new CasillaVacia(aux);
                    }
                    else if (casilla == movs[i + 1]) {
                        pieza2->set_color_casilla(aux2);
                        tab.asignar(c, f, pieza2);
                    }
                }
            }
        }
    }
    
}



void OnDraw(void)
{
	//Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0, 10, // posicion del ojo
		0.0, 0, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
	glOrtho;
	//en este caso dibujamos solo un cubo de alambre
	//aqui es donde hay que poner el código de dibujo


	//aqui es donde hay que poner el código de dibujo

	//Al final, cambiar el buffer (redibujar)
	//no borrar esta linea ni poner nada despues

	menu.dibuja();
	glutSwapBuffers();
}

void OnTimer(int value)
{

	//poner aqui el código de animacion


	//no borrar estas lineas

	glutTimerFunc(4, OnTimer, 0);
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
		menu.clica(x, y);

	}
}
void MouseMove(int x, int y)
{
	menu.detecta(x, y);
}