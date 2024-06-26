#pragma once
#include <vector>


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

class VectorCoordenadas : public std::vector<Coordenadas> {
public:

	void eliminar(const Coordenadas&); //elimina la coordenada si coinciden los parametros
	const VectorCoordenadas operator+ (const VectorCoordenadas& e); //devuelve un vector concatenado
	void operator+= (const VectorCoordenadas& e); //se concatena el vector de entrada a la funci�n
	void operator+= (const Coordenadas& e); //se a�ade como �ltimo par�metro del vector
	bool operator<<(const Coordenadas& e); //comprueba que las coordenadas formen parte de este vector

	VectorCoordenadas() = default;

	~VectorCoordenadas() {

	}

	bool operator==(const VectorCoordenadas& other) const;

	VectorCoordenadas(const std::vector<Coordenadas>& _v)
		: vector(_v) {};
};