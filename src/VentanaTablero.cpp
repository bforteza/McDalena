#include "VentanaTablero.h"
void VentanaTablero::detecta(GLdouble x, GLdouble y)
{
	Ventana::detecta(x,y);
	 tx = x - Ancho / 2;
	 ty = Alto / 2 - y;

	int auxx, auxy;
	

	Color color = NEGRO;


	auxx = (int) (((tx - origenx) / (lado))  + 1);
	auxy = (int) (((ty - origeny) / (lado))   + 1);


	if (Coordenadas(auxx, auxy) < tablero.get_tam())
		get_CasillaVacia({ auxx,auxy })->set_verde();

	
}

void VentanaTablero::click()
{

	Ventana::click();

	

	int auxx, auxy;
	


	auxx = (int) ((tx - origenx) / (lado)) + 1;
	auxy = (int) ((ty - origeny) / (lado)) + 1;

	tablero.entrada({auxx,auxy});
	

}

CasillaVacia*& VentanaTablero::get_CasillaVacia(const Coordenadas entrada)
{
	if (entrada < tablero.get_tam())
		return base[entrada.col - 1 + (entrada.fil - 1) * (tablero.get_tam().col)];

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
	for (int f = 1; f <= tablero.get_tam().fil; f++) {
		for (int c = 1; c <= tablero.get_tam().col; c++) {

			auxx = (c - 1) * lado + origenx + lado / 2;
			auxy = (f - 1) * lado + origeny + lado / 2;

			auxiliares.col = c;
			auxiliares.fil = f;
			get_CasillaVacia(auxiliares)->print(auxx, auxy);
			if (tablero.get_pieza(auxiliares) != nullptr && (!(auxiliares == tablero.Piezaamover) || tablero.seleccion.v.empty()))
				tablero.get_pieza(auxiliares)->print(auxx, auxy);
			


		}
	}
	if ( tablero.Piezaamover < tablero.get_tam() && !tablero.seleccion.v.empty())
		tablero.get_pieza(tablero.Piezaamover)->print(tx, ty);
	
	glPopMatrix();
	

}

VentanaTablero::VentanaTablero(const GLdouble& Ancho, const GLdouble& Alto, std::string Path, Juego juego)
	: tablero(juego), Ventana::Ventana(Ancho, Alto, Path)
{
	if (juego == UP) {
		origenx = -Ancho / 4;
		origeny = -Alto / 4;
		lado = Ancho / 8;
	}

	if (juego == SC) {
		origenx = -Ancho/4;
		origeny = -Alto/4;
		lado = Ancho/10;
	}


	base.resize(tablero.get_tam().fil * tablero.get_tam().col);
	Color color = BLANCO;
	int x = 1;
	for (auto& iter : base) {

		iter = new CasillaVacia(color,lado);

		color = !color;
		
		if (x % tablero.get_tam().col == 0 && !(tablero.get_tam().col % 2 ) ) {
			color = !color;
		}
		x++;
	}

	for (auto& iter : tablero.get_cuadricula()) {
		if (iter != nullptr)
			iter->set_size(lado, lado);
	}
	
	add_boton(Boton(100, 100, -300, 300, "bin/imagenes/Volver.png", "bin/imagenes/PreVolver.png", nullptr));
	add_boton(Boton(50, 50, 300, 300, "bin/imagenes/restart.png", "bin/imagenes/restartrojo.png", std::bind(&VentanaTablero::restart,this) ) ) ;
	
}

void VentanaTablero::restart() {
	tablero.restart();
	for (auto& iter : tablero.get_cuadricula()) {
		if (iter != nullptr)
			iter->set_size(lado, lado);
	}
}