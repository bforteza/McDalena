#include "Alfil.h"
#include "Tablero.h"

void Alfil::print(int col, int fil, double origenx, double origeny) {

	//std::cout << ((color_pieza == NEGRO) ? "A" : "a");
		if(color_casilla==NEGRO)
		{
			if (color_pieza == NEGRO)
			{
				sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
				sprite_pieza = new Sprite("imagenes/AlfilN.png", 1.66 + origenx+ fil * 1.072 - 1.65, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);
			}
			if (color_pieza == BLANCO)
			{
				sprite_casilla = new Sprite("imagenes/cuadrado2.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
				sprite_pieza = new Sprite("imagenes/AlfilB.png", 1.66 + origenx+ fil * 1.072 - 1.65, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

			}
		}
		if (color_casilla == BLANCO)
		{
			if (color_pieza == NEGRO)
			{
				sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
				sprite_pieza = new Sprite("imagenes/AlfilN.png", 1.66 + origenx+ fil * 1.072 - 1.65, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

			}
			if (color_pieza == BLANCO)
			{
				sprite_casilla = new Sprite("imagenes/cuadrado.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
				sprite_pieza = new Sprite("imagenes/AlfilB.png", 1.66 + origenx+ fil * 1.072 - 1.65, -2.5 + origeny -1.072 * col + 2.45, 0.8, 0.8);

			}
		}
		if (color_casilla == VERDE)
		{
			if (color_pieza == NEGRO)
			{
				sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
				sprite_pieza = new Sprite("imagenes/AlfilN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

			}
			if (color_pieza == BLANCO)
			{
				sprite_casilla = new Sprite("imagenes/cuadradoverde.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
				sprite_pieza = new Sprite("imagenes/AlfilB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

			}
		}
		if (color_casilla == ROJO)
		{
			if (color_pieza == NEGRO)
			{
				sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
				sprite_pieza = new Sprite("imagenes/AlfilN.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

			}
			if (color_pieza == BLANCO)
			{
				sprite_casilla = new Sprite("imagenes/cuadradorojo.png", origenx + 1.08 * fil, origeny - 1.08 * col, 1.2, 1.2);
				sprite_pieza = new Sprite("imagenes/AlfilB.png", 1.66 + origenx + fil * 1.072 - 1.65, -2.5 + origeny - 1.072 * col + 2.48, 0.8, 0.8);

			}
		}
		sprite_pieza->draw();
		sprite_casilla->draw();
		
	
	
}

bool Alfil::premove(Tablero* tablero, int columna, int fila) {
	int col = columna;
	int fil = fila;
	bool retorno = false;
	
	Casilla* aux;
	for (int auxcol = -1;auxcol <= 1; auxcol += 2) {    
		for (int auxfil = -1; auxfil <= 1; auxfil += 2) {   //recorre las cuatro diagonales
			col = columna; //volver a la casilla de inicio
			fil = fila;
			aux = tablero->get_casilla(col + auxcol, fil + auxfil); //Diagonal 
			while (aux != nullptr && !aux->ocupado()) {
				aux->color_casilla = ROJO;
				retorno = true;
				aux->selecionada = true;
				col+= auxcol;
				fil+= auxfil;
				aux = tablero->get_casilla(col + auxcol, fil + auxfil);
			}
			//Prueba si la ultima pieza ocupada es de su color o del contrario
			if (aux != nullptr && aux->ocupado() && dynamic_cast<Pieza*>(aux)->get_color_pieza() != color_pieza) { 
				aux->color_casilla = ROJO;
				aux->selecionada = true;
				retorno = true;
			}
		}
	}
	return retorno;
}

 void Alfil:: mover(Tablero* tablero, int posx, int posy, int cvx, int cvy) {

	if(color_pieza == BLANCO){
	 
	 tablero->asignar(posx, posy, new Alfil(BLANCO));
	}

	else if (color_pieza ==NEGRO) {

		tablero->asignar(posx, posy, new Alfil(NEGRO));
	}


	 if (posx!= cvy || posy != cvx) {

		tablero->asignar(cvy, cvx, new CasillaVacia(BLANCO));
	 }
	 



}