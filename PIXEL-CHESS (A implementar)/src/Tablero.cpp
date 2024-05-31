#include "Tablero.h"
#include <iostream>

void Tablero::size(int columnas, int filas) {

	cuadricula.resize(filas);
	for (size_t i = 0; i < cuadricula.size(); i++) {
		cuadricula[i].resize(columnas+1); // Cambiar el número de columnas en cada fila
	}

	Color color = NEGRO;

	if (columnas % 2 != 0)
	{
		for (auto& fila : cuadricula) {
			for (auto& casilla : fila) {
				casilla = new CasillaVacia(color);
				color = !color;
			}
			color = !color;
		}
	}
	if (columnas % 2 == 0)
	{
		for (auto& fila : cuadricula) {
			for (auto& casilla : fila) {
				casilla = new CasillaVacia(color);
				color = !color;
			}
		}
	}

	
	
}

Tablero::Tablero(Juego juego) {
	if (juego == UP) {
		size(D, 5);
		origenx = -1.66;
		origeny = 2.50;

		asignar(C,1 , new Alfil(BLANCO));
		asignar(B,5, new Alfil(NEGRO));

		asignar(B, 1, new Caballo(BLANCO));
		asignar(C, 5, new Caballo(NEGRO));

		asignar(D, 1, new Torre(BLANCO));
		asignar(A, 5, new Torre(NEGRO));

		asignar(A, 1, new Rey(BLANCO));
		asignar(D, 5, new Rey(NEGRO));

		asignar(A, 2, new Peon(BLANCO));
		asignar(D, 4, new Peon(NEGRO));


	}
	else if (juego == SC) {

		size(E, 6); //falta implementar todas las piezas
		origenx = -1.96;
		origeny = 2.85;

	}
}

Tablero::Tablero(Tablero& entrada) {
	cuadricula = entrada.cuadricula;
	for (auto& fila : cuadricula) {
		for (auto& casilla : fila) {
			casilla = casilla->puntero();
		}
	}
}

void Tablero::print() {

	int coord_fila = 0, coord_columna = 0;
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

	int num = 1;

	for (auto fila : cuadricula) {
		
		std::cout << num++<< " ";
		for (auto casilla : fila) {
			casilla->print(coord_fila,coord_columna,origenx,origeny);
			
			coord_columna++;
		}
		std::cout << "\n";
		coord_columna = 0;
		coord_fila++;
		
	}
	std::cout << "\n\n";
} //falta mejorar el metodo print para que las casillas aparezcan en su lugar

Casilla*& Tablero::get_casilla(int col, int fil) {
	Casilla* retorno = nullptr;
	if (fil-1 >= 0 && fil-1 < cuadricula.size() && col >= 0 && col < cuadricula[0].size())
		return cuadricula[fil-1][col];
	return retorno;
}

void Tablero::asignar(int col, int fil, Casilla* entrada) {
	
	
	entrada->set_color_casilla(cuadricula[fil-1][col]->get_color_casilla());
	delete cuadricula[fil-1][col];
	cuadricula[fil-1][col] = entrada;
	
	
}

bool Tablero::premove(int col, int fil) {
	

	borrar_seleccion();

	if (get_casilla(col, fil)->premove(this, col, fil)) { 
		Color color_pieza = dynamic_cast<Pieza*>(get_casilla(col, fil))->get_color_pieza();
		int auxfil = 1;
		int auxcol = A;

		for (auto& fila : cuadricula) {
			auxcol = A;
			for (auto& casilla : fila) {
				if (casilla->selecionada == 1) {

					Tablero tablero(*this);
					tablero.fmove(col, fil, auxcol, auxfil);

					if (tablero.jaque(!color_pieza))
						casilla->selecionada = false;	
				}
				auxcol++;
			}
			auxfil++;
		}
		for (auto& fila : cuadricula) {
			for (auto& casilla : fila) {
				if (casilla->selecionada == true) return true;
			}
		}
	}
	
	return false;
}

void Tablero::borrar_seleccion() {
	for (auto& fila : cuadricula) {
		for (auto& casilla : fila) {
			casilla->selecionada = 0;
		}
	}
}

bool Tablero::jaque(Color color) {
	Tablero tablero(*this);
	Rey* rey = tablero.get_rey(!color);
	int fil = 1;
	int col = A;
	for (auto& fila : tablero.cuadricula) {
		col = A;
		for (auto& casilla : fila) {

			
			if (casilla->ocupado() && dynamic_cast<Pieza*>(casilla)->get_color_pieza() == color
				&& casilla->premove(&tablero , col, fil) && rey->selecionada == true) {
				
				tablero.borrar_seleccion();
				return true;
			}
		
			col++;
		}
		fil++;
	}
	return false;

}

Rey* Tablero::get_rey(Color color) {
	for (auto& fila : cuadricula) {
		for (auto& casilla : fila) {
			if (casilla->ocupado() && dynamic_cast<Pieza*>(casilla)->get_color_pieza() == color
				&& dynamic_cast<Rey*>(casilla) != nullptr) {
				return dynamic_cast<Rey*>(casilla);
			}
		}
	}
	return nullptr;
}

bool Tablero::fmove(int Ocol, int Ofil, int Dcol, int Dfil) {
	Casilla*& Origen = get_casilla(Ocol, Ofil);
	Casilla*& Destino = get_casilla(Dcol, Dfil);
	movimientos.push_back(Origen);
	movimientos.push_back(Destino);
	Color aux = Origen->get_color_casilla();
	Color aux2 = Destino->get_color_casilla();
	if (Origen == nullptr || Destino == nullptr || !Origen->ocupado()) return false;

	delete Destino;
	Destino = Origen;
	Destino->set_color_casilla(aux2);
	Origen = new CasillaVacia(aux);
	
	return true;
}

bool Tablero::mate(Color color) {
	if (jaque(color) && ahogado(!color)) return true;
	return false; 
}

bool Tablero::ahogado(Color color) {
	Tablero tablero(*this);
	int auxcol = A;
	int auxfil = 1;
	for (auto& fila : tablero.cuadricula) {
		auxcol = A;
		for (auto& casilla : fila) {
			if (casilla->ocupado() && dynamic_cast<Pieza*>(casilla)->get_color_pieza() == color &&
				 tablero.premove(auxcol, auxfil))
				return false; //comprueba que no se puede hacer ningun movimiento
			auxcol++;
		}
		auxfil++;
	}
	return true;
}
void Tablero::detectar(int x, int y)
{
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
}
void Tablero::clicar(int x, int y, int& estado)
{
	if ((x > 97) && (x < 153))
	{
		if ((y > 39) && (y < 83))
		{
			estado = 0;
		}
	}
}