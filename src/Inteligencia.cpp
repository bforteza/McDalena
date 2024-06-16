#include "Inteligencia.h"

int Inteligencia::evalue()
{
	int retorno=0;
	for (auto& iter : p_blancas) {
		retorno += get_pieza(iter)->puntos();
	}
	for (auto iter : p_negras) {
		retorno -= get_pieza(iter)->puntos();
	}
	return retorno;
}
