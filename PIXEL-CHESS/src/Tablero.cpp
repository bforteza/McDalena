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
	Torre1_Negro.dibuja(Torre1_Negro.coordenadas, Torre1_Negro.equipo);
	Torre1_Blanco.dibuja(Torre1_Blanco.coordenadas, Torre1_Blanco.equipo);
	Caballo1_Negro.dibuja(Caballo1_Negro.coordenadas, Caballo1_Negro.equipo);
	Caballo1_Blanco.dibuja(Caballo1_Blanco.coordenadas, Caballo1_Blanco.equipo);
	Alfil1_Negro.dibuja(Alfil1_Negro.coordenadas, Alfil1_Negro.equipo);
	Alfil1_Blanco.dibuja(Alfil1_Blanco.coordenadas, Alfil1_Blanco.equipo);
	Rey1_Negro.dibuja(Rey1_Negro.coordenadas, Rey1_Negro.equipo);
	Rey1_Blanco.dibuja(Rey1_Blanco.coordenadas, Rey1_Blanco.equipo);

}
void Tablero::inicializa()
{
	
	casillas.push_back({Casilla11,Casilla12,Casilla13,Casilla14});
	casillas.push_back({ Casilla21,Casilla22,Casilla23,Casilla24 });
	casillas.push_back({ Casilla31,Casilla32,Casilla33,Casilla34 });
	casillas.push_back({ Casilla41,Casilla42,Casilla43,Casilla44 });
	casillas.push_back({ Casilla51,Casilla52,Casilla53,Casilla54 });
	/*

	casillas.push_back({ new Sprite("imagenes/cuadrado.png", -1.66, -1.82, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", -0.58,  -1.82, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado.png", 0.5, -1.82, 1.2, 1.2)
		,new Sprite("imagenes/cuadrado2.png", 1.58, -1.82, 1.2, 1.2) });

	
	*/
}