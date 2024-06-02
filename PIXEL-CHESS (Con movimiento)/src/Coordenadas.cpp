#include "Coordenadas.h"

bool Coordenadas::operator < (const Coordenadas& e) {

	return (col > 0 && fil > 0 && col <= e.col && fil <= e.fil);

}

Coordenadas Coordenadas::operator+(Coordenadas& e) const
{
	return Coordenadas(col + e.col, fil + e.fil);
}


void Coordenadas::operator+=(Coordenadas e)
{
	col += e.col;
	fil += e.fil;
}

const VectorCoordenadas VectorCoordenadas::operator+(const VectorCoordenadas& e)
{
	VectorCoordenadas retorno;
	retorno += *this;
	retorno += e;
	return retorno;
}

void VectorCoordenadas::operator+=(const VectorCoordenadas& e)
{
	v.reserve(v.size() + e.v.size());
	for (auto& iter : e.v) { v.push_back(new Coordenadas(*iter)); }
}

void VectorCoordenadas::operator+=(Coordenadas& e)
{
	v.push_back(&e);
}

void VectorCoordenadas::operator+=(Coordenadas* e)
{
	v.push_back(e);
}

void VectorCoordenadas::clear()
{
	for (auto ele : v) {
		if (ele != nullptr)
			delete ele;
		ele = nullptr;
	}
	v.clear();
}

void VectorCoordenadas::operator<=(VectorCoordenadas& e)
{
	v.reserve(v.size() + e.v.size());
	v.insert(v.end(), e.v.begin(), e.v.end());
	for (auto& iter : e.v)
		iter = nullptr;
}
