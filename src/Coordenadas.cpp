#include "Coordenadas.h"

bool Coordenadas::operator < (const Coordenadas& e) const {
	
	return (col > 0 && fil > 0 && col <= e.col && fil <= e.fil);
		
}

Coordenadas Coordenadas::operator+(const Coordenadas& e) const 
{
	return Coordenadas(col+e.col,fil+e.fil);
}

void Coordenadas::operator+=(const Coordenadas e)
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
	v.insert(v.end(), e.v.begin(), e.v.end());
}

void VectorCoordenadas::operator+=(const Coordenadas& e)
{
	v.push_back(e);
}

void VectorCoordenadas::clear()
{	
	v.clear();
}

bool VectorCoordenadas::operator<<(Coordenadas& e)
{
	for (auto& iter : v) {
		if (iter == e)
			return true;
	}
	return false;
}

void VectorCoordenadas::eliminar(const Coordenadas& e)
{
	int i = 0;
	for (auto& iter : v) {
		if (iter == e) {
			v.erase(v.begin() + i);
		}
		i++;
	}
}






