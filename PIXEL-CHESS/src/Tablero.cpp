#include "Tablero.h"
#include "CasillaVacia.h"
#include <iostream>
void Tablero::dibujafondo()
{
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	//Habilitamos la carga de texturas 2D
	glBindTexture(GL_TEXTURE_2D,
	//Cargamos el sprite de fondo
	ETSIDI::getTexture("imagenes/Fondo.png").id);
	glEnable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	//Generamos un polígono que cuadre en la ventana
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(-5.0, 5.0, -0.5);
	glTexCoord2d(1, 1); glVertex3d(5.0, 5.0, -0.5);
	glTexCoord2d(1, 0); glVertex3d(5.0, -5.0, -0.5);
	glTexCoord2d(0, 0); glVertex3d(-5.0, -5.0, -0.5);
	glEnd();
	//Habilitamos la luz para una mejor vista
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}


Tablero::Tablero(Columna columnas, int filas) {

	int i=0, j=0; //Dos parámetros para la carga de casillas (x,y)
	cuadricula.resize(filas); //Hacemos lo suficientemente grandes las filas
	for (size_t i = 0; i < cuadricula.size(); i++) {
		cuadricula[i].resize(columnas + 1); // Cambiamos el número de columnas en cada fila
	}

	Color color = NEGRO; //Color de inicio de casilla
	Sprite *sprite = new Sprite("imagenes/cuadrado2.png", -1.66, 2.50, 1.2, 1.2);//Su sprite correspondiente
	for (auto& fila : cuadricula) { //recorremos las filas
		for (auto& casilla : fila) {//recorremos las columnas
			if (j % 2 == 0) //Si la fila es par
			{
				if (i % 2 == 0)//Si la fila es par
					casilla = new CasillaVacia({ NEGRO }, new Sprite("imagenes/cuadrado2.png", -1.66 + i * 1.08, 2.50 - j * 1.08, 1.2, 1.2), { i,j });
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
				if (i % 2 != 0)//Si la fila es impar
					casilla = new CasillaVacia({ BLANCO }, new Sprite("imagenes/cuadrado.png", -1.66 + i * 1.08, 2.50 - j * 1.08, 1.2, 1.2), { i,j });
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
			}
			if (j % 2 != 0)//Si la fila es impar
			{
				if (i % 2 == 0)//Si la fila es par
					casilla = new CasillaVacia({ BLANCO }, new Sprite("imagenes/cuadrado.png", -1.66 + i * 1.08, 2.50 - j * 1.08, 1.2, 1.2), { i,j });
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
				if (i % 2 != 0)//Si la fila es impar
					casilla = new CasillaVacia({ NEGRO }, new Sprite("imagenes/cuadrado2.png", -1.66 + i * 1.08, 2.50 - j * 1.08, 1.2, 1.2), { i,j });
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)

			}
			i++; //cambio de columna
		}
		i = 0;//reseteo de columna al cambiar de fila
		j++;//cambio de fila
	}
	
}

void Tablero::print() {
	for (auto fila : cuadricula) {//recorremos las filas
		for (auto casilla : fila) {//recorremos las columnas
			casilla->print();//Imprimimos la casilla
		}
		std::cout << "\n";
	}
	//Dibujamos la torre negra
	Torre1_Negro.dibuja(Torre1_Negro.coordenadas,NEGRO);
	//Dibujamos la torre blanca
	Torre1_Blanco.dibuja(Torre1_Blanco.coordenadas, BLANCO);
	//Dibujamos el caballo negro
	Caballo1_Negro.dibuja(Caballo1_Negro.coordenadas, NEGRO);
	//Dibujamos el caballo blanco
	Caballo1_Blanco.dibuja(Caballo1_Blanco.coordenadas, BLANCO);
	//Dibujamos el alfil negro
	Alfil1_Negro.dibuja(Alfil1_Negro.coordenadas, NEGRO);
	//Dibujamos el alfil blanco
	Alfil1_Blanco.dibuja(Alfil1_Blanco.coordenadas, BLANCO);
	//Dibujamos el rey negro
	Rey1_Negro.dibuja(Rey1_Negro.coordenadas, NEGRO);
	//Dibujamos el rey blanco
	Rey1_Blanco.dibuja(Rey1_Blanco.coordenadas, BLANCO);
	//Dibujamos el peon negro
	Peon1_Negro.dibuja(Peon1_Negro.coordenadas, NEGRO);
	//Dibujamos el peon blanco
	Peon1_Blanco.dibuja(Peon1_Blanco.coordenadas, BLANCO);
}