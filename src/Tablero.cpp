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
			if (dynamic_cast<Rey*>(get_pieza(*iter)) != nullptr) {
				return *iter;
			}
		}
	}
	if (color == NEGRO) {
		for (auto& iter : p_negras.v) {
			if (dynamic_cast<Rey*>(get_pieza(*iter)) != nullptr) {
				return *iter;
			}
		}
	}
}

void Tablero::print() {

	for (int f = tam.fil; f != 0; f--) {
		std::cout << f;
		for (int c = 1; c <= tam.col; c++) {
			bool punto = false;
			for (auto& sel : seleccion.v) {

				if(Coordenadas(c,f) == *sel){
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
}

void Tablero::seleccionar(const VectorCoordenadas& e)
{
	seleccion += e;
}

void Tablero::borrar_seleccion()
{
	seleccion.clear();
}

VectorCoordenadas Tablero::premove(const Coordenadas& e)
{
	Pieza* aux = get_pieza(e);
	if (aux != nullptr)
		return aux->premove(this, e);
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
					p_blancas += new Coordenadas(c, f);
				else
					p_negras += new Coordenadas(c, f);
			}
		}
	}
}

