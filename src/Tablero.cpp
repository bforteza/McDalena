#include "Tablero.h"

Tablero::Tablero(Juego juego) {
	if (juego == SC) {
		tam.fil = 6;
		tam.col = 6;
		
	}
	if (juego == UP) {
		tam.fil = 5;
		tam.col = 4;
		origenx = -300;
		origeny = -350;
	}
	finalx = origenx + tam.fil * lado;
	finaly = origeny + tam.col * lado;

	cuadricula.resize(tam.fil * tam.col);
	base.resize(tam.fil * tam.col);
	Color color = BLANCO;
	int x=1;
	for (auto& iter : base) {
		iter = new CasillaVacia(color);
		
		x++;
		if (x%tam.col != 1) {
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

		asignar({ B,3 }, new Rey(BLANCO));
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

Pieza*& Tablero::get_pieza(const Coordenadas entrada) {

	if (entrada < tam)
		return cuadricula[entrada.col - 1 + (entrada.fil - 1) * (tam.col)];

	Pieza* retorno = nullptr;
	return retorno;
}

CasillaVacia*& Tablero::get_CasillaVacia(const Coordenadas entrada)
{
	if (entrada < tam)
		return base[entrada.col - 1 + (entrada.fil - 1) * (tam.col)];

	CasillaVacia* retorno = nullptr;
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

void Tablero::dibuja() {

	gluPerspective(90.0, 800 / 800.0f, 400, 500);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 400, // posicion del ojo
		    0.0, 0, 0.0, // hacia que punto mira (0,0,0)
		    0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 


	

	glDisable(GL_LIGHTING);
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	//Habilitamos la carga de texturas 2D
	glBindTexture(GL_TEXTURE_2D,
		//Cargamos el sprite de fondo
		ETSIDI::getTexture("bin/imagenes/Fondo.png").id);
	
	glBegin(GL_POLYGON);
	//glTranslated(-450, -450, 0);
	//Generamos un polígono que cuadre en la ventana
	GLfloat a = 400;
	glTexCoord2d(0, 1); glVertex3d(-a, a, 0);
	glTexCoord2d(1, 1); glVertex3d(a, a, 0);
	glTexCoord2d(1, 0); glVertex3d(a, -a, 0);
	glTexCoord2d(0, 0); glVertex3d(-a, -a, 0 );
	glEnd();
	//Habilitamos la luz para una mejor vista
	
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	
	glPushMatrix();
	glTranslated(origenx + lado/2, origeny + lado/2, 0);
	for (auto& iter : seleccion.v) {
		get_CasillaVacia(iter)->set_rojo();
	}
	GLdouble auxx, auxy;
	for (int f = 1; f <= tam.fil; f++) {
		for (int c = 1; c <= tam.col; c++) {
			
			auxx =  (c - 1) * lado;
			auxy =  (f - 1) * lado;
			
			
			get_CasillaVacia({ c,f })->print(auxx, auxy, lado);
			if (get_pieza({ c,f }) != nullptr)
				get_pieza({ c,f })->print(auxx, auxy, lado);
			

		}
	}

	glPopMatrix();

	
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
	fmove(Piezaamover, e);
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

void Tablero::detectar(int x, int y)
{
	int auxx, auxy;
	auxx = x - 400;
	auxy = 400 - y;
	
	Color color = NEGRO;


	auxx = ((auxx -  origenx) / (lado)) + 1;
	auxy = ((auxy -  origeny) / (lado)) + 1;


	if (Coordenadas(auxx, auxy) < tam)
		get_CasillaVacia({ auxx,auxy })->set_verde();

}

void Tablero::clicar(int x, int y)
{

	int auxx, auxy;
	auxx = x - 400;
	auxy = 400 - y;

	
	auxx = ((auxx - origenx) / (lado)) + 1;
	auxy = ((auxy - origeny) / (lado)) + 1;
	Coordenadas aux(auxx, auxy);


	if (((turno == BLANCO) ? p_blancas : p_negras) << aux && Piezaamover.col == 0) {
		Piezaamover = aux;
		seleccionar(premove(aux));
	} else if (Piezaamover.col && seleccion << aux) {
		move(aux);
		borrar_seleccion();
		Piezaamover.col = 0;
		turno = !turno;

	} else if (Piezaamover.col && !(seleccion << aux) && !(aux == Piezaamover)) {
	
		borrar_seleccion();
		Piezaamover.col = 0;

	}

}

Pieza* Tablero::get_pieza(const Coordenadas entrada) const
{
	if (entrada < tam)
		return cuadricula[entrada.col - 1 + (entrada.fil - 1) * (tam.col)];
	return nullptr;
}