#include "Tablero.h"
#include <iostream>


int coordalfilx = 2, coordalfily = 1;

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
		spriteorigenx = 212;
		spriteorigeny = 60;
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
		spriteorigenx = 179;
		spriteorigeny = 27;

		asignar(C, 1, new Alfil(BLANCO));
		asignar(C, 6, new Alfil(NEGRO));

		asignar(D, 1, new Caballo(BLANCO));
		asignar(B, 6, new Caballo(NEGRO));

		asignar(E, 1, new Torre(BLANCO));
		asignar(A, 6, new Torre(NEGRO));

		asignar(B, 1, new Rey(BLANCO));
		asignar(D, 6, new Rey(NEGRO));

		asignar(A, 1, new Reina(BLANCO));
		asignar(E, 6, new Reina(NEGRO));


		for (int i = A; i<=E; i++)
		{
			asignar(i, 2, new Peon(BLANCO));
			asignar(i, 5, new Peon(NEGRO));
		}

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
		
		for (auto casilla : fila) {
			casilla->print(coord_fila,coord_columna,origenx,origeny);
			
			coord_columna++;
		}
		coord_columna = 0;
		coord_fila++;
		
	}
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

int c=1; // Coordenadas click x
int u=1; // Coordenadas click y
int prex=1, prey=1; // Coordenadas previas


void Tablero::detectar(int x, int y,Juego juego)
{
	int i = 0, j = 0;
	Casilla* aux = nullptr;
	aux = new CasillaVacia(VERDE);
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
		for (auto& fila : cuadricula) {
			for (auto& casilla : fila) {
				casilla->color_casilla = color;
				color = !color;
			}
			color = !color;
		}
	}
	if (juego == SC)
	{
		for (auto& fila : cuadricula) {
			for (auto& casilla : fila) {
				casilla->color_casilla = color;
				color = !color;
			}
		}
	}




			for (auto& fila : cuadricula) {
				for (auto& casilla : fila) {
					if ((x > (spriteorigenx + j * 115)) && x < (spriteorigenx + 115 + j * 115))
					{
						if ((y > spriteorigeny + i * 105) && (y < spriteorigeny + 105 + i * 105))
						{
							
							aux->sprite_casilla = new Sprite("imagenes/cuadradoverde.png", float(origenx + 1.08 * j), float(origeny - 1.08 *i), 1.2, 1.2);
							cuadricula.at(i).at(j)->sprite_casilla = aux->sprite_casilla;
							cuadricula.at(i).at(j)->color_casilla = aux->color_casilla;
							
						}
					}

					j++;
				}

		

			j = 0;
			i++;
			
			}


			


			premove(c, u);

}
















void Tablero::clicar(int x, int y, int& estado, Juego juego, int& coordenadas_x, int& coordenadas_y)
{
	int i = 0, j = 0;
	Casilla* aux = nullptr;
	aux = new CasillaVacia(VERDE);
	Color color = NEGRO;


	if ((x > 97) && (x < 153))
	{
		if ((y > 39) && (y < 83))
		{
			estado = 0;
		}
	}

	for (auto& fila : cuadricula) {
		for (auto& casilla : fila) {
			if ((x > (spriteorigenx + j * 115)) && x < (spriteorigenx + 115 + j * 115))
			{
				if ((y > spriteorigeny + i * 105) && (y < spriteorigeny + 105 + i * 105))
				{
					coordenadas_x = j;
					c = j;
					coordenadas_y = i+1;
					u = i + 1;


					if ((get_casilla(coordenadas_x, coordenadas_y)->color_casilla != ROJO)) {

						prex = coordenadas_x;
						prey = coordenadas_y;
						std::cout << c << "," << u << std::endl;
						std::cout << prex<<","<<prey << std::endl;


					}
					if ((get_casilla(coordenadas_x, coordenadas_y)->color_casilla == ROJO) ) {

						
						coordalfilx = coordenadas_x;
						coordalfily = coordenadas_y;
						std::cout << "HOLA" << std::endl;
						std::cout << c << "," << u << std::endl;
						std::cout << prex << "," << prey << std::endl;


					}
					//std::cout << coordenadas_x << ',' << coordenadas_y<<std::endl;
					
					if (juego == UP)
					{
						
						cuadricula[prey-1][prex]->mover(this,c,u,prey,prex);  // coordenadas_x y coordenadas_y deben ser coordenadas que sean iguales al click escepto cuando se clica algo rojo // prex y prey deben ser coordenadas que cambian cuando se clica algo rojo y no cambain 
						


					}
					if (juego == SC)
					{
						cuadricula[prey - 1][prex]->mover(this, c, u, prey, prex);
					}
					
					if (juego == UP)
					{
						for (auto& fila : cuadricula) {
							for (auto& casilla : fila) {
								casilla->color_casilla = color;
								color = !color;
							}
							color = !color;
						}
					}
					if (juego == SC)
					{
						for (auto& fila : cuadricula) {
							for (auto& casilla : fila) {
								casilla->color_casilla = color;
								color = !color;
							}
						}
					}


					aux->sprite_casilla = new Sprite("imagenes/cuadradorojo.png", float(origenx + 1.08 * j), float(origeny - 1.08 * i), 1.2, 1.2);
					cuadricula.at(i).at(j)->sprite_casilla = aux->sprite_casilla;
					cuadricula.at(i).at(j)->color_casilla = aux->color_casilla;
				
					
				}
			}

			j++;
		}
	


		j = 0;
		i++;

		
	}


	
	premove(c, u);
	

}