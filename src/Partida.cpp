#include "Partida.h"

void Partida::guardar(Tablero& tab)
{
    // Verificar que el tablero tiene tamaño válido
    auto tam = tab.get_tam();
    if (tam.fil <= 0 || tam.col <= 0) {
        std::cerr << "Tamaño de tablero inválido" << std::endl;
        return;
    }

    for (int f = 0; f < tam.fil; f++) {
        for (int c = 0; c < tam.col; c++) {
            Pieza* pieza = tab.get_pieza(Coordenadas(c, f));
            // Verificar que la pieza es válida antes de agregarla al vector
            if (pieza != nullptr) {
                pieza->set_tipo();
                posicionesg.push_back(pieza);
            }
            else {
                posicionesg.push_back(nullptr);
            }
        }
    }

    std::ofstream gtxt("guardado");
    if (gtxt.is_open()) {
        for (const auto pieza : posicionesg) {
            if (pieza != nullptr) {
                pieza->gpieza(gtxt);
            }
            else continue;
        }
        gtxt.close();
    }
    else {
        std::cerr << "No se pudo realizar el guardado" << std::endl;
    }
}

void Partida::cargar(Juego juego, Tablero& tab)
{
	std::ifstream gtxt("guardado");
	vector<Pieza*> piezas;
	if (gtxt.is_open()) {
		Pieza pieza(BLANCO);
		int color;
		std::string tip{};
		while (gtxt >> color >> tip) {
			pieza.cpieza(color, tip);
			piezas.push_back(new Pieza(pieza)); //Introduzco un puntero a la nueva pieza
		}
		gtxt.close();
	}
	else {
		std::cerr << "No se pudo abrir el archivo para la carga" << std::endl;
	}

	Tablero::Tablero(juego, piezas);
}