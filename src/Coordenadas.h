#pragma once
#include <vector>

class Coordenadas {
public:
	int col, fil;

	Coordenadas(int _col, int _fil) :col(_col), fil(_fil) {};
	Coordenadas() = default;
	Coordenadas(Coordenadas& e) : col(e.col), fil(e.fil) {};
	Coordenadas(const Coordenadas& e) : col(e.col), fil(e.fil) {};

	bool operator < (const Coordenadas& e);

	bool operator == (const Coordenadas& other) const
	{
		return col == other.col && fil == other.fil;
	}

	Coordenadas operator + (Coordenadas& e) const;
	void operator += (Coordenadas e);
};

class VectorCoordenadas {
public:

	std::vector<Coordenadas*> v{};

	void operator<= (VectorCoordenadas& e);
	const VectorCoordenadas operator+ (const VectorCoordenadas& e);
	void operator+= (const VectorCoordenadas& e);
	void operator+= (Coordenadas& e);
	void operator+= (Coordenadas* e);
	void clear();

	

	~VectorCoordenadas() {

		for (auto ele : v) {
			if (ele != nullptr)
			delete ele;
			ele = nullptr;
		}
		v.clear();
	}
	
};