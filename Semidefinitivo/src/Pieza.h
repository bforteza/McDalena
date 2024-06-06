#pragma once
#include <vector>
#include "Coordenadas.h"
#include <iostream>
#include "ETSIDI.h"
#include <fstream>
#include <string>

class Tablero;

using std::vector;
using ETSIDI::Sprite;

enum Columna { A = 1, B, C, D, E, F, G };
enum Color { BLANCO = 0, NEGRO = 1};
Color operator !(Color color);



class Pieza
{
protected:
	Color color{};
	std::string tipo{};

	Sprite* sprite_pieza{}; //Sprite Correspondiente
	float lado=150;
public:
	//metodos otención de datos
	virtual Color get_color() { return color; };

	virtual void print(const GLdouble x, const GLdouble y) {
		glTranslated(x, y, 0);
		sprite_pieza->draw();
		glTranslated(-x, -y, 0);
	};

	virtual VectorCoordenadas premove(Tablero* tablero, const Coordenadas& posicion) {
		VectorCoordenadas res;
		return res;
	};

	VectorCoordenadas premove_dir(Coordenadas(&dir)[4], Tablero* tablero, const Coordenadas& posicion);
	void set_color(Color color_asignado) {
		color = color_asignado;
	}

	void set_size(float ancho, float alto) {
		sprite_pieza->setSize(ancho, alto);
		sprite_pieza->setCenter(ancho / 2, alto / 2);
	}

	//inicializador
	Pieza(Color pieza) : color(pieza) {};

	//Sobrecargas y métodos para el guardado

	virtual void gpieza(std::ofstream& out) const {}
	void cpieza(int c, std::string t);
	std::string get_tipo() { return tipo; }

	friend std::ostream& operator<<(std::ostream& os, const Pieza& p) {
		os << static_cast<int>(p.color);
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Pieza& p) {
		int c;
		is >> c;
		p.color = static_cast<Color>(c);
		return is;
	}
	
};
