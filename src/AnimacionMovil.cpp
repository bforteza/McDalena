#include "AnimacionMovil.h"
#include "iostream"
void AnimacionMovil::anima()
{
	glPushMatrix();
	glTranslated(1, 1, 1);

	coordenadasx = coordenadasx + 10;
	if (coordenadasx == 400)
	{
		coordenadasy = ETSIDI::lanzaDado(300.0, -300.0F);
		coordenadasx = -400;
	}



	animacion_reloj++;
	if (animacion_reloj == _columnas)
		animacion_reloj = 1;


	secuencia = { _Direccion.c_str(),_filas,_columnas,_tiempo,true,coordenadasx,coordenadasy,_ancho,_alto, animacion_reloj };
	glPopMatrix();
}