#include "Coordenadas.h"

bool Coordenadas::operator < (const Coordenadas& e) const {

	return (col > 0 && fil > 0 && col <= e.col && fil <= e.fil);

}

Coordenadas Coordenadas::operator+(const Coordenadas& e) const
{
	return Coordenadas(col + e.col, fil + e.fil);
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
	reserve(size() + e.size());
	insert(end(), e.begin(), e.end());
}

void VectorCoordenadas::operator+=(const Coordenadas& e)
{
	push_back(e);
}



bool VectorCoordenadas::operator<<(const Coordenadas& e)
{
	for (auto& iter : *this) {
		if (iter == e)
			return true;
	}
	return false;
}

void VectorCoordenadas::eliminar(const Coordenadas& e)
{
	int i = 0;
	for (auto& iter : *this) {
		if (iter == e) {
			erase(begin() + i);
			return;
		}
		i++;
	}
}






