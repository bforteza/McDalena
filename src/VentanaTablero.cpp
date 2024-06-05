#include "VentanaTablero.h"
void VentanaTablero::detecta(GLdouble x, GLdouble y)
{

	GLdouble tx = x - Ancho / 2;
	GLdouble ty = Alto / 2 - y;

	int auxx, auxy;
	

	Color color = NEGRO;


	auxx = (int) ((tx - origenx) / (lado)) + 1;
	auxy = (int) ((ty - origeny) / (lado)) + 1;


	if (Coordenadas(auxx, auxy) < tablero.tam)
		get_CasillaVacia({ auxx,auxy })->set_verde();

}

void VentanaTablero::click(GLdouble x, GLdouble y)
{

	Ventana::click(x, y);

	GLdouble tx = x - Ancho / 2;
	GLdouble ty = Alto / 2 - y;

	int auxx, auxy;
	


	auxx = (int) ((tx - origenx) / (lado)) + 1;
	auxy = (int) ((ty - origeny) / (lado)) + 1;
	Coordenadas aux(auxx, auxy);


	if (((tablero.turno == BLANCO) ? tablero.p_blancas : tablero.p_negras) << aux && tablero.Piezaamover.col == 0) {
		tablero.Piezaamover = aux;
		tablero.seleccionar(tablero.premove(aux));
	}
	else if (tablero.Piezaamover.col && tablero.seleccion << aux) {
		tablero.move(aux);
		tablero.borrar_seleccion();
		tablero.Piezaamover.col = 0;
		tablero.turno = !tablero.turno;

	}
	else if (tablero.Piezaamover.col && !(tablero.seleccion << aux) && !(aux == tablero.Piezaamover)) {

		tablero.borrar_seleccion();
		tablero.Piezaamover.col = 0;

	}

}

CasillaVacia*& VentanaTablero::get_CasillaVacia(const Coordenadas entrada)
{
	if (entrada < tablero.tam)
		return base[entrada.col - 1 + (entrada.fil - 1) * (tablero.tam.col)];

	CasillaVacia* retorno = nullptr;
	return retorno;
}

void VentanaTablero::dibuja() {

	Ventana::dibuja();


		



	glPushMatrix();
	glTranslated(origenx + lado / 2, origeny + lado / 2, 0);
	for (auto& iter : tablero.seleccion.v) {
		get_CasillaVacia(iter)->set_rojo();
	}
	GLdouble auxx, auxy;
	for (int f = 1; f <= tablero.tam.fil; f++) {
		for (int c = 1; c <= tablero.tam.col; c++) {

			auxx = (c - 1) * lado;
			auxy = (f - 1) * lado;


			get_CasillaVacia({ c,f })->print(auxx, auxy, lado);
			if (tablero.get_pieza({ c,f }) != nullptr)
				tablero.get_pieza({ c,f })->print(auxx, auxy, lado);


		}
	}

	glPopMatrix();
	

}

VentanaTablero::VentanaTablero(const GLdouble& Ancho, const GLdouble& Alto, std::string Path, Juego juego)
	: tablero(juego), Ventana::Ventana(Ancho, Alto, Path)
{
	base.resize(tablero.tam.fil * tablero.tam.col);
	Color color = BLANCO;
	int x = 1;
	for (auto& iter : base) {
		iter = new CasillaVacia(color);

		x++;
		if (x % tablero.tam.col != 1) {
			color = !color;
		}
	}

	if (juego == UP) {
		origenx = -300;
		origeny = -300;
		lado = 100;
	}
}
