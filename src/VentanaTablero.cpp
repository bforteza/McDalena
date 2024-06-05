#include "VentanaTablero.h"
void VentanaTablero::detecta(GLdouble x, GLdouble y)
{

	 tx = x - Ancho / 2;
	 ty = Alto / 2 - y;

	int auxx, auxy;
	

	Color color = NEGRO;


	auxx =  ((tx - origenx) / (lado)) + 1;
	auxy =  ((ty - origeny) / (lado)) + 1;


	if (Coordenadas(auxx, auxy) < tablero.tam)
		get_CasillaVacia({ auxx,auxy })->set_verde();

	
}

void VentanaTablero::click(GLdouble x, GLdouble y)
{

	Ventana::click(x, y);

	

	int auxx, auxy;
	


	auxx = (int) ((tx - origenx) / (lado)) + 1;
	auxy = (int) ((ty - origeny) / (lado)) + 1;

	tablero.entrada({auxx,auxy});
	

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
	
	for (auto& iter : tablero.seleccion.v) {
		get_CasillaVacia(iter)->set_rojo();
	}
	GLdouble auxx, auxy;
	Coordenadas auxiliares;
	for (int f = 1; f <= tablero.tam.fil; f++) {
		for (int c = 1; c <= tablero.tam.col; c++) {

			auxx = (c - 1) * lado + origenx + lado / 2;
			auxy = (f - 1) * lado + origeny + lado / 2;

			auxiliares.col = c;
			auxiliares.fil = f;
			get_CasillaVacia(auxiliares)->print(auxx, auxy);
			if (tablero.get_pieza(auxiliares) != nullptr && !(auxiliares == tablero.Piezaamover))
				tablero.get_pieza(auxiliares)->print(auxx, auxy);
			


		}
	}
	if ( tablero.Piezaamover < tablero.tam)
		tablero.get_pieza(tablero.Piezaamover)->print(tx, ty);
	
	glPopMatrix();
	

}

VentanaTablero::VentanaTablero(const GLdouble& Ancho, const GLdouble& Alto, std::string Path, Juego juego)
	: tablero(juego), Ventana::Ventana(Ancho, Alto, Path)
{
	if (juego == UP) {
		origenx = -100;
		origeny = -100;
		lado = 75;
	}



	base.resize(tablero.tam.fil * tablero.tam.col);
	Color color = BLANCO;
	int x = 1;
	for (auto& iter : base) {
		iter = new CasillaVacia(color,lado);

		x++;
		if (x % tablero.tam.col != 1) {
			color = !color;
		}
	}

	for (auto& iter : tablero.cuadricula) {
		if (iter != nullptr)
			iter->set_size(lado, lado);
	}
}
