#pragma once
#include "Animacion.h"
#include "iostream"
class AnimacionMovil:public Animacion
{
	int animacion_reloj=0;
public:
	AnimacionMovil(std::string Direccion, int columnas, int filas, int tiempo, float x, float y, float ancho, float alto)
		:Animacion(Direccion,columnas,filas,tiempo,x,y,ancho,alto)
	{
		
	}

	virtual void anima();
};

