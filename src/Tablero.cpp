#include "Tablero.h"

Tablero::Tablero(Juego juego){
	if (juego == SC) {
		tam.fil = 6;
		tam.col = 6;
	}

	cuadricula.resize( tam.fil * tam.col );

	for (auto& iter : cuadricula) {
		iter = nullptr;
	}

	if (juego == SC) {
		for (int c = 1; c <= tam.col; c++) {
			asignar({ c , 2 }, new Peon(BLANCO));
			asignar({ c , 5 }, new Peon(NEGRO));
		}
		asignar({ C,3 }, new Reina(BLANCO));
		asignar({ A,1 }, new Rey(BLANCO));
		asignar({ A,6 }, new Rey(NEGRO));
	}

	buscar_piezas();
}

Pieza*& Tablero::get_pieza(Coordenadas entrada) {
	
	if(entrada<tam)
	return cuadricula[entrada.col - 1 + (entrada.fil - 1) * (tam.col)];

	Pieza* retorno = nullptr;
	return retorno;
}

Coordenadas Tablero::rey(Color color)
{
	if (color == BLANCO) {
		for (auto& iter : p_blancas.v) {
			if (dynamic_cast<Rey*>(get_pieza(iter)) != nullptr) {
				return iter;
			}
		}
	}
	if (color == NEGRO) {
		for (auto& iter : p_negras.v) {
			if (dynamic_cast<Rey*>(get_pieza(iter)) != nullptr) {
				return iter;
			}
		}
	}
	return Coordenadas();
}

void Tablero::print() {

	for (int f = tam.fil; f != 0; f--) {
		std::cout << f;
		for (int c = 1; c <= tam.col; c++) {
			bool punto = false;
			for (auto& sel : seleccion.v) {

				if(Coordenadas(c,f) == sel){
					std::cout << ".";
					punto = true;
				}		
				
			}
			if(punto == false)
				std::cout << " ";

			if (get_pieza({ c,f }) != nullptr)
				get_pieza({ c,f })->print();
			else
				std::cout << " ";
			
		}
		std::cout << "\n";
	}
	std::cout << " ";
	char letra = 'A';
	for (int c = 1; c <= tam.col; c++) {
	
		std::cout << " " << letra;
		letra++;
	}	
	std::cout << "\n";
}

bool Tablero::jaque(Color color)
{
	VectorCoordenadas& piezas = (color == BLANCO) ? p_blancas : p_negras;
	VectorCoordenadas VCaux;
	Coordenadas c_rey = rey(!color);
	for (auto& aux : piezas.v) {
		VCaux += get_pieza(aux)->premove(this, aux);
		if (VCaux << c_rey)
			return true;
	}
	return false;
}

void Tablero::seleccionar(const VectorCoordenadas& e)
{
	seleccion += e;
}

void Tablero::borrar_seleccion()
{
	seleccion.clear();
}

bool Tablero::fmove(const Coordenadas& origen, const Coordenadas& destino)
{
	bool muerte = false;
	Pieza*& pdestino = get_pieza(destino);
	Pieza*& porigen = get_pieza(origen);
	if (pdestino != nullptr) {
		muertas.push_back(pdestino);
		muerte = true;
		switch (pdestino->get_color())
		{
		case BLANCO:
			p_blancas.eliminar(destino);
			break;
		case NEGRO:
			p_negras.eliminar(destino);
			break;
		default:
			break;
		}
	}
	switch (porigen->get_color())
	{
	case BLANCO:
		p_blancas.eliminar(origen);
		p_blancas += destino;
		break;
	case NEGRO:
		p_negras.eliminar(origen);
		p_negras += destino;
		break;
	default:
		break;
	}
	pdestino = porigen;
	porigen = nullptr;
	int i = 0;

	return muerte;
	
}

VectorCoordenadas Tablero::premove(const Coordenadas& e)
{
	Pieza* aux = get_pieza(e);
	if (aux != nullptr) {
		bool muerte = false;
		VectorCoordenadas premoves;
		
		Color c_pieza = aux->get_color();
		if (aux != nullptr) {
			premoves += aux->premove(this, e);

			for (auto& iter : premoves.v) {

				muerte = fmove(e, iter);
				if (jaque(!c_pieza))
					premoves.eliminar(iter);
				fmove(iter, e);
				if (muerte)
					get_pieza(iter) = muertas.back();
			}

			return premoves;

		}
	}
	return VectorCoordenadas();
}

void Tablero::asignar(Coordenadas e, Pieza* entrada) {
	if (get_pieza(e) == nullptr) {
		get_pieza(e) = entrada;
	}
}

void Tablero::buscar_piezas()
{
	p_blancas.clear();
	p_negras.clear();
	for (int f = tam.fil; f != 0; f--) {
		for (int c = 1; c <= tam.col; c++) {
			if (get_pieza({ c,f }) != nullptr) {
				if (get_pieza({ c,f })->get_color() == BLANCO)
					p_blancas += Coordenadas(c, f);
				else
					p_negras += Coordenadas(c, f);
			}
		}
	}
}


