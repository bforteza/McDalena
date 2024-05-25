#include "Tablero.h"

void Tablero::dibuja()
{

	casillas.at(0).at(0).dibuja();
	casillas.at(0).at(1).dibuja();
	casillas.at(0).at(2).dibuja();
	casillas.at(0).at(3).dibuja();

	casillas.at(1).at(0).dibuja();
	casillas.at(1).at(1).dibuja();
	casillas.at(1).at(2).dibuja();
	casillas.at(1).at(3).dibuja();

	casillas.at(2).at(0).dibuja();
	casillas.at(2).at(1).dibuja();
	casillas.at(2).at(2).dibuja();
	casillas.at(2).at(3).dibuja();

	casillas.at(3).at(0).dibuja();
	casillas.at(3).at(1).dibuja();
	casillas.at(3).at(2).dibuja();
	casillas.at(3).at(3).dibuja();

	casillas.at(4).at(0).dibuja();
	casillas.at(4).at(1).dibuja();
	casillas.at(4).at(2).dibuja();
	casillas.at(4).at(3).dibuja();
	
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