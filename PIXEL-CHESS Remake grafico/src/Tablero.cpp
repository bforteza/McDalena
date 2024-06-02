#include "Tablero.h"

Tablero::Tablero(Juego juego) {
	if (juego == SC) {
		tam.fil = 6;
		tam.col = 5;
		origenx = -3.25;
		origeny = 3.85;
		spriteorigenx = 179;
		spriteorigeny = 27;

	}
	if (juego == UP) {
		tam.fil = 5;
		tam.col = 4;
		origenx = -2.75;
		origeny = 3.45;
		spriteorigenx = 212;
		spriteorigeny = 60;
	}

	cuadricula.resize(tam.fil * tam.col);
	base.resize(tam.fil);
	for (size_t i = 0; i < base.size(); i++) {
		base[i].resize(tam.col); // Cambiar el número de columnas en cada fila
	}
	Color color = NEGRO;

	for (auto& iter : cuadricula) {
		iter = nullptr;
	}
	if (tam.col % 2 != 0)
	{
		for (auto& fila : base) {
			for (auto& casilla : fila) {
				casilla = new CasillaVacia(color);
				color = !color;
			}
		}
	}
	if (tam.col % 2 == 0)
	{
		for (auto& fila : base) {
			for (auto& casilla : fila) {
				casilla = new CasillaVacia(color);
				color = !color;
			}
			color = !color;
		}
	}
	
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

		asignar({ A , 2 }, new Peon(BLANCO));
		asignar({ D , 4 }, new Peon(NEGRO));

		asignar({ A,1 }, new Rey(BLANCO));
		asignar({ D,5 }, new Rey(NEGRO));

		asignar({ C,1 }, new Alfil(BLANCO));
		asignar({ B,5 }, new Alfil(NEGRO));

		asignar({ B,1 }, new Caballo(BLANCO));
		asignar({ C,5 }, new Caballo(NEGRO));

		asignar({ D,1 }, new Torre(BLANCO));
		asignar({ A,5 }, new Torre(NEGRO));
	}
	buscar_piezas();
}

Pieza*& Tablero::get_pieza(Coordenadas entrada) {

	if (entrada < tam)
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

	int coord_fila = 1, coord_columna = 1;
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	//Habilitamos la carga de texturas 2D
	glBindTexture(GL_TEXTURE_2D,
		//Cargamos el sprite de fondo
		ETSIDI::getTexture("imagenes/Fondo.png").id);
	glEnable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	//Generamos un polígono que cuadre en la ventana
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(-5.0, 5.0, -0.5);
	glTexCoord2d(1, 1); glVertex3d(5.0, 5.0, -0.5);
	glTexCoord2d(1, 0); glVertex3d(5.0, -5.0, -0.5);
	glTexCoord2d(0, 0); glVertex3d(-5.0, -5.0, -0.5);
	glEnd();
	//Habilitamos la luz para una mejor vista
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	volver.draw();


	for (int f = tam.fil; f != 0; f--) {
		for (int c = 1; c <= tam.col; c++) {
			bool punto = false;
			for (auto& sel : seleccion.v) {

				if (Coordenadas(c, f) == sel) {
					//base.at(c).at(f)->set_color(ROJO);
					punto = true;
				}

			}
			if (punto == false)
			//base.at(c).at(f)->set_color(ROJO);
			if (get_pieza({ c,f }) != nullptr)
				get_pieza({ c,f })->print(f,c,origenx,origeny);

		}
	}
	char letra = 'A';

	for (auto& fila : base) {
		
		for (auto& casilla : fila) {	
			casilla->print(coord_fila, coord_columna, origenx, origeny);
			coord_columna++;
			
		}
		coord_columna = 1;
		coord_fila++;
	}
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
int c = 1; // Coordenadas click x
int u = 1; // Coordenadas click y
int prex = 1, prey = 1; // Coordenadas previas

void Tablero::detectar(int x, int y, Juego juego)
{
	int i = 0, j = 0;
	Color color = NEGRO;

	if ((x > 97) && (x < 153))
	{
		if ((y > 39) && (y < 83))
		{
			volver = { "imagenes/Volver.png", -3,3,1, 1 };
		}
		else
		{
			volver = { "imagenes/PreVolver.png", -3,3,1, 1 };
		}
	}
	else
	{
		volver = { "imagenes/PreVolver.png", -3,3,1, 1 };
	}


	if (juego == UP)
	{
		for (auto& fila : base) {
			for (auto& casilla : fila) {
				casilla->set_color(color);
				color = !color;
			}
			color = !color;
		}
	}
	if (juego == SC)
	{
		for (auto& fila : base) {
			for (auto& casilla : fila) {
				casilla->set_color(color);
				color = !color;
			}
		}
	}




	for (auto& fila : base) {
		for (auto& casilla : fila) {
			if ((x > (spriteorigenx + j * 115)) && x < (spriteorigenx + 115 + j * 115))
			{
				if ((y > spriteorigeny + i * 105) && (y < spriteorigeny + 105 + i * 105))
				{

					base.at(i).at(j)->set_color(VERDE);

				}
			}

			j++;
		}



		j = 0;
		i++;

	}





	//premove(c, u);

}
void Tablero::clicar(int x, int y, int& estado, Juego juego, int& coordenadas_x, int& coordenadas_y)
{
	coordenadas_x = 1, coordenadas_y = 1;
	int i = 0, j = 0;
	Color color = NEGRO;


	if ((x > 97) && (x < 153))
	{
		if ((y > 39) && (y < 83))
		{
			estado = 0;
		}
	}

	for (auto& fila : base) {
		for (auto& casilla : fila) {
			if ((x > (spriteorigenx + j * 115)) && x < (spriteorigenx + 115 + j * 115))
			{
				if ((y > spriteorigeny + i * 105) && (y < spriteorigeny + 105 + i * 105))
				{

					//std::cout << coordenadas_x << ',' << coordenadas_y<<std::endl;

					if (juego == UP)
					{

						//base[prey - 1][prex]->mover(this, c, u, prey, prex);  // coordenadas_x y coordenadas_y deben ser coordenadas que sean iguales al click escepto cuando se clica algo rojo // prex y prey deben ser coordenadas que cambian cuando se clica algo rojo y no cambain 



					}
					if (juego == SC)
					{
						//base[prey - 1][prex]->mover(this, c, u, prey, prex);
					}

					if (juego == UP)
					{
						for (auto& fila : base) {
							for (auto& casilla : fila) {
								casilla->set_color(color);
								color = !color;
							}
							color = !color;
						}
					}
					if (juego == SC)
					{
						for (auto& fila : base) {
							for (auto& casilla : fila) {
								casilla->set_color(color);
								color = !color;
							}
						}
					}
					base.at(i).at(j)->set_color(ROJO);
					seleccionar(premove({ i,j }));


				}
			}

			j++;
		}
		j = 0;
		i++;
	}
	//premove(c, u);

}