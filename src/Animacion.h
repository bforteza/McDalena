#pragma once
#include "freeglut.h"
#include <string>
#include <functional>
#include "ETSIDI.h"
class Animacion
{
protected:
	ETSIDI::SpriteSequence secuencia{ "imagenes/pixelchessanimacion.png", 10 };
	float coordenadasx, coordenadasy;
	int _columnas, _filas;
	int _tiempo;
	float _ancho, _alto;
	std::string _Direccion;
public:

	Animacion(std::string Direccion, int columnas, int filas, int tiempo, float x, float y, float ancho, float alto)
	{
		coordenadasx = x;
		coordenadasy = y;
		_columnas = columnas;
		_filas = filas;
		_tiempo = tiempo;
		_ancho = ancho;
		_alto = alto;
		_Direccion = Direccion;

		secuencia = { Direccion.c_str(),filas,columnas,tiempo,true,x,y,ancho,alto };
	}

	void dibuja();
	virtual void anima();
};


