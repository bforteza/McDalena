#include "Partida.h"

void Partida::guardar(Tablero& tab)
{
	for (int f = 0; f < tab.get_tam().fil; f++) {
		for (int c = 0; c < tab.get_tam().col; c++)
		{
			posicionesg.push_back(tab.get_pieza(Coordenadas(c,f)));
		}
	}//Guardo las posiciones de todas las piezas en el momento en el que se decide guardar la partida

	std::ofstream gtxt("guardado");
	if (gtxt.is_open()) {
		for (const auto& pieza : posicionesg) {
			pieza->gpieza(gtxt);
		}
		gtxt.close();
	}
	else {
		std::cerr << "No se pudo realizar el guardado" << std::endl;
	}
}

void Partida::cargar(vector<Pieza*>& piezas, Juego juego)
{
	std::ifstream gtxt("guardado");

	if (gtxt.is_open()) {
		Pieza pieza(BLANCO);
		Pieza* p = &pieza;
		int color;
		std::string tip{};
		while (gtxt >> color >> tip) {
			pieza.cpieza(color,tip);
			piezas.push_back(p); //Introduzco un puntero a la nueva pieza
		}
		gtxt.close();
	}
	else {
		std::cerr << "No se pudo abrir el archivo para la carga" << std::endl;
	}

	Tablero::Tablero(juego,piezas);
}