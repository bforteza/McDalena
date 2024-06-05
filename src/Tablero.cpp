#include "Tablero.h"

Tablero::Tablero(Juego _juego) {
	juego = _juego;
	restart();
}

Pieza*& Tablero::get_pieza(const Coordenadas entrada) {

	if (entrada < tam)
		return cuadricula[entrada.col - 1 + (entrada.fil - 1) * (tam.col)];

	Pieza* retorno = nullptr;
	return retorno;
}

Coordenadas Tablero::rey(const Color color)
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
		
		premoves += aux->premove(this, e);

		for (auto& iter : vector<Coordenadas>(premoves.v) ) {

			muerte = fmove(e, iter);
			if (jaque(!c_pieza))
				premoves.eliminar(iter);
			fmove(iter, e);
			if (muerte) {
				get_pieza(iter) = muertas.back();
				muertas.pop_back();
				((c_pieza==BLANCO) ? p_negras : p_blancas)  += iter;
			}

		}

		return premoves;

	}
	return VectorCoordenadas();
}

void Tablero::move(const Coordenadas& e)
{
	//coronación
	Pieza*& aux = get_pieza(Piezaamover);
	if (dynamic_cast<Peon*>(aux) != nullptr && (e.fil == tam.fil || e.fil == 1 )) {
		Color Peoncolor = aux->get_color();
		delete aux;
		aux = new Reina(Peoncolor);
	}
	//enroque
	if (dynamic_cast<Rey*>(aux) != nullptr ) {
		if (e.col - Piezaamover.col == 2) {
			fmove(e + Coordenadas(1, 0), Piezaamover + Coordenadas(1, 0));
			dynamic_cast<Rey*>(aux)->move = true;
		}
		if (e.col - Piezaamover.col == -2) {
			fmove(e + Coordenadas(-1, 0), Piezaamover + Coordenadas(-1, 0));
			dynamic_cast<Rey*>(aux)->move = true;
		}
	}
	if (dynamic_cast<Torre*>(aux) != nullptr) {
		dynamic_cast<Torre*>(aux)->move = true;
	}

	fmove(Piezaamover, e);
	borrar_seleccion();
	Piezaamover.col = 0;
	Piezaamover.fil = 0;
	turno = !turno;

	
}

void Tablero::entrada(const Coordenadas& e)
{
	if (((turno == BLANCO) ? p_blancas : p_negras) << e && Piezaamover.col == 0) {
		seleccionar(premove(e));
		if (!seleccion.v.empty())
			Piezaamover = e;
	}
	else if (Piezaamover.col && seleccion << e) {
		move(e);
	}
	else if (Piezaamover.col && !(seleccion << e) && !(e == Piezaamover)) {

		borrar_seleccion();
		Piezaamover.col = 0;

	}
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

Pieza* Tablero::get_pieza(const Coordenadas entrada) const
{
	if (entrada < tam)
		return cuadricula[entrada.col - 1 + (entrada.fil - 1) * (tam.col)];
	return nullptr;
}

vector<Pieza*>& Tablero::get_cuadricula()
{
	return cuadricula;
}

void Tablero::restart()
{
	for (auto& iter : cuadricula) {
		if (iter != nullptr)
			delete iter;
	}
	for (auto& iter : muertas) {
		if (iter != nullptr)
			delete iter;
	}
	cuadricula.clear();
	muertas.clear();
	p_blancas.clear();
	p_negras.clear();

	
	if (juego == SC) {
		tam.fil = 6;
		tam.col = 5;

	}
	if (juego == UP) {
		tam.fil = 5;
		tam.col = 4;

	}


	cuadricula.resize(tam.fil * tam.col);


	if (juego == SC) {
		for (int c = 1; c <= tam.col; c++) {
			asignar({ c , 2 }, new Peon(BLANCO));
			asignar({ c , 5 }, new Peon(NEGRO));
		}
		asignar({ A,1 }, new Reina(BLANCO));
		asignar({ E,6 }, new Reina(NEGRO));

		asignar({ B,1 }, new Rey(BLANCO));
		asignar({ D,6 }, new Rey(NEGRO));

		asignar({ C,1 }, new Alfil(BLANCO));
		asignar({ C,6 }, new Alfil(NEGRO));

		asignar({ D,1 }, new Caballo(BLANCO));
		asignar({ B,6 }, new Caballo(NEGRO));

		asignar({ E,1 }, new Torre(BLANCO));
		asignar({ A,6 }, new Torre(NEGRO));


	}
	if (juego == UP) {

		asignar({ D , 2 }, new Peon(BLANCO));
		asignar({ A , 4 }, new Peon(NEGRO));

		asignar({ D,1 }, new Rey(BLANCO));
		asignar({ A,5 }, new Rey(NEGRO));

		asignar({ B,1 }, new Alfil(BLANCO));
		asignar({ C,5 }, new Alfil(NEGRO));

		asignar({ C,1 }, new Caballo(BLANCO));
		asignar({ B,5 }, new Caballo(NEGRO));

		asignar({ A,1 }, new Torre(BLANCO));
		asignar({ D,5 }, new Torre(NEGRO));
	}
	buscar_piezas();
	
}
