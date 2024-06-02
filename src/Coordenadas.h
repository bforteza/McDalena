#pragma once
#include <vector>
#include <memory>

class Coordenadas {
public:
	char col, fil;

	Coordenadas(int _col, int _fil) :col(_col), fil(_fil) {};
	Coordenadas() = default;
	Coordenadas(Coordenadas& e) : col(e.col), fil(e.fil) {};
	Coordenadas(const Coordenadas& e) : col(e.col), fil(e.fil) {};

	bool operator < (const Coordenadas& e) const;

	bool operator == (const Coordenadas& other) const
	{
		return col == other.col && fil == other.fil;
	}

	Coordenadas operator + (const Coordenadas& e) const;
	void operator += (const Coordenadas e);
};

class VectorCoordenadas {
public:

	std::vector<Coordenadas> v{};

	void eliminar(const Coordenadas&); //elimina la coordenada si coinciden los parametros
	const VectorCoordenadas operator+ (const VectorCoordenadas& e); //devuelve un vector concatenado
	void operator+= (const VectorCoordenadas& e); //se concatena el vector de entrada a la función
	void operator+= (const Coordenadas& e); //se añade como último parámetro del vector

	void clear(); //vacia el vector

	bool operator<<(Coordenadas& e); //comprueba que las coordenadas formen parte de este vector

	VectorCoordenadas() = default;

	~VectorCoordenadas() {
		v.clear();
	}
	
	bool operator==(const VectorCoordenadas& other) const;
};