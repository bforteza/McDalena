#include "freeglut.h"
#include "ETSIDI.h"
#include "Tablero.h"
#include "iostream"

Tablero tablero1(D, 5);


void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int boton, int state, int x, int y);
void MouseMove(int x, int y);


int main(int argc, char* argv[])
{

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
	//en este caso dibujamos solo un cubo de alambre
	//aqui es donde hay que poner el código de dibujo


	//aqui es donde hay que poner el código de dibujo

	//Al final, cambiar el buffer (redibujar)
	//no borrar esta linea ni poner nada despues

	tablero1.dibujafondo();
	//Dibujamos el fondo del tablero 1
	tablero1.print();
	//Dibujamos el tablero 1
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
		tablero1.clicar(x, y);

	}
}
void MouseMove(int x, int y)
{
	tablero1.detectar(x, y);
}