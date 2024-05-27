#include "Tablero.h"
#include "CasillaVacia.h"
#include <iostream>
bool clicado = false;
Vector2D coordenadas_click = { 7,7 };
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
	volver.draw();
}


Tablero::Tablero(Columna columnas, int filas,float origen_x,float origen_y, 
	const int spriteorigen_x, const int spriteorigen_y, int _modalidad) {

		modalidad = _modalidad;
		marca_origenx = origen_x;
		marca_origeny = origen_y;
		marca_filas = filas;
		marca_columnas = columnas;
		marca_spritex = spriteorigen_x;
		marca_spritey = spriteorigen_y;
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
					casilla = new CasillaVacia({ NEGRO }, new Sprite("imagenes/cuadrado2.png", origen_x + i * 1.08, origen_y - j * 1.08, 1.2, 1.2));
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
				if (i % 2 != 0)//Si la fila es impar
					casilla = new CasillaVacia({ BLANCO }, new Sprite("imagenes/cuadrado.png", origen_x + i * 1.08, origen_y - j * 1.08, 1.2, 1.2));
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
			}
			if (j % 2 != 0)//Si la fila es impar
			{
				if (i % 2 == 0)//Si la fila es par
					casilla = new CasillaVacia({ BLANCO }, new Sprite("imagenes/cuadrado.png", origen_x + i * 1.08, origen_y - j * 1.08, 1.2, 1.2));
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
				if (i % 2 != 0)//Si la fila es impar
					casilla = new CasillaVacia({ NEGRO }, new Sprite("imagenes/cuadrado2.png", origen_x + i * 1.08, origen_y - j * 1.08, 1.2, 1.2));
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)

			}
			i++; //cambio de columna
		}
		i = 0;//reseteo de columna al cambiar de fila
		j++;//cambio de fila
	}

	if (_modalidad == 0)
	{

	//Torres blanca y negra inicializadas
	 TorreNegra = new Torre{ { 3,0 }, NEGRO, 0, new Sprite("imagenes/TorreN.png", -0.66, 0.44, 0.8, 0.8) };
	 TorreBlanca = new	Torre{ {0,4},BLANCO,0,new Sprite("imagenes/TorreB.png", 2.58, -1.74, 0.8, 0.8) };
	
	//Caballos blanco y negro inicializados
	 CaballoNegro = new Caballo{ {1,0},NEGRO,0,new Sprite("imagenes/CaballoN.png", -0.64, 0.44, 0.8, 0.8) };
	 CaballoBlanco = new Caballo{ {2,4},BLANCO,0,new Sprite("imagenes/caballoB.png", 2.62, -1.72, 0.8, 0.8) };

	//Alfiles blanco y negro inicializados
	 AlfilNegro = new Alfil{ {2,0},NEGRO,0,new Sprite("imagenes/AlfilN.png", -0.66, 0.44, 0.8, 0.8) };
	 AlfilBlanco = new Alfil{ {1,4},BLANCO,0,new Sprite("imagenes/AlfilB.png", 2.58, -1.72, 0.8, 0.8) };

	//Reyes blanco y negro inicializados
	 ReyNegro = new Rey{ {0,0},NEGRO,0,new Sprite("imagenes/ReyN.png", -0.66, 0.42, 0.8, 0.8) };
	 ReyBlanco = new Rey{ {3,4},BLANCO,0,new Sprite("imagenes/ReyB.png", 2.62, -1.74, 0.8, 0.8) };

	//Peones blanco y negro inicializados
	 PeonesNegros.resize(1);
	 PeonesBlancos.resize(1);
	PeonesNegros.at(0) = new Peon{{0,1},NEGRO,0,new Sprite("imagenes/PeonN.png", -0.64, 0.42, 0.74, 0.74)};
	PeonesBlancos.at(0) = new Peon{{3,3},BLANCO,0,new Sprite("imagenes/PeonB.png", 2.62, -1.74, 0.84, 0.84)};
	}
	if (_modalidad == 1)
	{

		//Torres blanca y negra inicializadas
		TorreNegra = new Torre{ { 4,0 }, NEGRO, 0, new Sprite("imagenes/TorreN.png", -0.90, 0.72, 0.8, 0.8) };
		TorreBlanca = new	Torre{ {0,5},BLANCO,0,new Sprite("imagenes/TorreB.png", 2.32, -1.47, 0.8, 0.8) };

		//Caballos blanco y negro inicializados
		CaballoNegro = new Caballo{ {3,0},NEGRO,0,new Sprite("imagenes/CaballoN.png", -0.90, 0.74, 0.8, 0.8) };
		CaballoBlanco = new Caballo{ {1,5},BLANCO,0,new Sprite("imagenes/caballoB.png", 2.38, -1.42, 0.8, 0.8) };

		//Alfiles blanco y negro inicializados
		AlfilNegro = new Alfil{ {2,0},NEGRO,0,new Sprite("imagenes/AlfilN.png", -0.92, 0.74, 0.8, 0.8) };
		AlfilBlanco = new Alfil{ {2,5},BLANCO,0,new Sprite("imagenes/AlfilB.png", 2.34, -1.41, 0.8, 0.8) };

		//Reyes blanco y negro inicializados
		ReyNegro = new Rey{ {1,0},NEGRO,0,new Sprite("imagenes/ReyN.png", -0.92, 0.74, 0.8, 0.8) };
		ReyBlanco = new Rey{ {3,5},BLANCO,0,new Sprite("imagenes/ReyB.png", 2.34, -1.43, 0.8, 0.8) };

		//Reyes blanco y negro inicializados
		ReinaNegra = new Reina{ {0,0},NEGRO,0,new Sprite("imagenes/ReinaN.png", -0.92, 0.72, 0.8, 0.8) };
		ReinaBlanca = new Reina{ {4,5},BLANCO,0,new Sprite("imagenes/ReinaB.png", 2.28, -1.48, 0.8, 0.8) };

		//Peones blanco y negro inicializados
		PeonesNegros.resize(5);
		PeonesBlancos.resize(5);
		i = 0;
		while (i < 5)
		{
			PeonesNegros.at(i) = new Peon{ {i,1},NEGRO,0,new Sprite("imagenes/PeonN.png", -0.92, 0.72, 0.70, 0.70) };
			PeonesBlancos.at(i) = new Peon{ {i,4},BLANCO,0,new Sprite("imagenes/PeonB.png", 2.34, -1.44, 0.8, 0.8) };
			i++;
		}
		
		
		//PeonesBlancos.at(0) = new Peon{ {3,3},BLANCO,0,new Sprite("imagenes/PeonB.png", 2.62, -1.74, 0.84, 0.84) };
	}
	
	
}

void Tablero::dibuja() {
	for (auto fila : cuadricula) {//recorremos las filas
		for (auto casilla : fila) {//recorremos las columnas
			casilla->print();//Imprimimos la casilla
		}
	}
	if (modalidad == 0)
	{
		//Dibujamos las torres
		TorreBlanca->dibuja(TorreBlanca->coordenadas, BLANCO);
		TorreNegra->dibuja(TorreNegra->coordenadas, NEGRO);

		//Dibujamos los caballos
		CaballoNegro->dibuja(CaballoNegro->coordenadas, NEGRO);
		CaballoBlanco->dibuja(CaballoBlanco->coordenadas, BLANCO);

		//Dibujamos los alfiles
		AlfilNegro->dibuja(AlfilNegro->coordenadas, NEGRO);
		AlfilBlanco->dibuja(AlfilBlanco->coordenadas, BLANCO);

		//Dibujam<os los reyes
		ReyNegro->dibuja(ReyNegro->coordenadas, NEGRO);
		ReyBlanco->dibuja(ReyBlanco->coordenadas, BLANCO);

		//Dibujamos el peon negro
		PeonesNegros.at(0)->dibuja(PeonesNegros.at(0)->coordenadas, NEGRO);
		//Dibujamos el peon blanco
		PeonesBlancos.at(0)->dibuja(PeonesBlancos.at(0)->coordenadas, BLANCO);
	}
	if (modalidad == 1)
	{
		//Dibujamos las torres
		TorreBlanca->dibuja(TorreBlanca->coordenadas, BLANCO);
		TorreNegra->dibuja(TorreNegra->coordenadas, NEGRO);

		//Dibujamos los caballos
		CaballoNegro->dibuja(CaballoNegro->coordenadas, NEGRO);
		CaballoBlanco->dibuja(CaballoBlanco->coordenadas, BLANCO);

		//Dibujamos los alfiles
		AlfilNegro->dibuja(AlfilNegro->coordenadas, NEGRO);
		AlfilBlanco->dibuja(AlfilBlanco->coordenadas, BLANCO);

		//Dibujam<os los reyes
		ReyNegro->dibuja(ReyNegro->coordenadas, NEGRO);
		ReyBlanco->dibuja(ReyBlanco->coordenadas, BLANCO);

		//Dibujam<os los reyes
		ReinaNegra->dibuja(ReinaNegra->coordenadas, NEGRO);
		ReinaBlanca->dibuja(ReinaBlanca->coordenadas, BLANCO);
		int i = 0;
		while (i < 5)
		{
			PeonesNegros.at(i)->dibuja(PeonesNegros.at(i)->coordenadas, NEGRO);
			PeonesBlancos.at(i)->dibuja(PeonesBlancos.at(i)->coordenadas, BLANCO);
			i++;
		}
		
	}
	
}
void Tablero::detectar(int x, int y)
{
		for (int i = 0; i < marca_columnas+1 ; i++)
		{
			origenx = marca_origenx;
			origeny = marca_origeny;
			spriteorigenx = marca_spritex;
			spriteorigeny = marca_spritey;
			for (int j = 0; j < marca_filas; j++)
			{

				if (j % 2 == 0) //Si la fila es par
				{
					if (i % 2 == 0)//Si la fila es par
						cuadricula.at(j).at(i) = new CasillaVacia({ NEGRO }, new Sprite("imagenes/cuadrado2.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
					//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
					if (i % 2 != 0)//Si la fila es impar
						cuadricula.at(j).at(i) = new CasillaVacia({ BLANCO }, new Sprite("imagenes/cuadrado.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
					//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
				}
				if (j % 2 != 0)//Si la fila es impar
				{
					if (i % 2 == 0)//Si la fila es par
						cuadricula.at(j).at(i) = new CasillaVacia({ BLANCO }, new Sprite("imagenes/cuadrado.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
					//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
					if (i % 2 != 0)//Si la fila es impar
						cuadricula.at(j).at(i) = new CasillaVacia({ NEGRO }, new Sprite("imagenes/cuadrado2.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
					//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)

				}

				if ((x > (spriteorigenx + i * 118)) && x < (spriteorigenx+118 + i * 118))
				{
					if ((y > spriteorigeny + j * 104) && (y < spriteorigeny+104 + 104 * j))
					{

						delete cuadricula.at(j).at(i);
		cuadricula.at(j).at(i) = new CasillaVacia({ BLANCO },
		new Sprite("imagenes/cuadradoverde.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
		clicado = true;
					}
				}
				if (j == coordenadas_click.x && i == coordenadas_click.y)
				{
					delete cuadricula.at(coordenadas_click.x).at(coordenadas_click.y);
					cuadricula.at(j).at(i) = new CasillaVacia({ BLANCO },
						new Sprite("imagenes/cuadradorojo.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
					clicado = true;
				}

			}
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
void Tablero::clicar(int x, int y, int &estado)
{
	for (int i = 0; i < marca_columnas+1; i++)
	{
		origenx = marca_origenx;
		origeny = marca_origeny;
		spriteorigenx = marca_spritex;
		spriteorigeny = marca_spritey;
		for (int j = 0; j < marca_filas; j++)
		{

			if (j % 2 == 0) //Si la fila es par
			{
				if (i % 2 == 0)//Si la fila es par
					cuadricula.at(j).at(i) = new CasillaVacia({ NEGRO }, new Sprite("imagenes/cuadrado2.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
				if (i % 2 != 0)//Si la fila es impar
					cuadricula.at(j).at(i) = new CasillaVacia({ BLANCO }, new Sprite("imagenes/cuadrado.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
			}
			if (j % 2 != 0)//Si la fila es impar
			{
				if (i % 2 == 0)//Si la fila es par
					cuadricula.at(j).at(i) = new CasillaVacia({ BLANCO }, new Sprite("imagenes/cuadrado.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)
				if (i % 2 != 0)//Si la fila es impar
					cuadricula.at(j).at(i) = new CasillaVacia({ NEGRO }, new Sprite("imagenes/cuadrado2.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
				//Las coordenadas de la casilla varían según se baja con xcasilla=x y casilla=(-y)

			}

			if ((x > (spriteorigenx + i * 118)) && x < (spriteorigenx + 118 + i * 118))
			{
				if ((y > spriteorigeny + j * 104) && (y < spriteorigeny + 104 + 104 * j))
				{

					delete cuadricula.at(j).at(i);
					cuadricula.at(j).at(i) = new CasillaVacia({ BLANCO },
						new Sprite("imagenes/cuadradorojo.png", origenx + i * 1.08, origeny - j * 1.08, 1.2, 1.2));
					coordenadas_click = { j,i };
					std::cout << coordenadas_click.x << ',' << coordenadas_click.y << std::endl;
				}
			}
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