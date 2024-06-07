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

	Coordenadas auxiliares = { auxx,auxy };
	if (auxiliares < tablero.get_tam())
	{
		get_CasillaVacia(auxiliares)->set_selecionado();
	}

		
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
			get_CasillaVacia(iter)->set_verde();
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
		if (tablero.Piezaamover < tablero.get_tam() && !tablero.seleccion.v.empty())
			tablero.get_pieza(tablero.Piezaamover)->print(tx, ty);

		turno.draw();
		glPopMatrix();


	
	if (tablero.coronacion == true && !ventana_coronado)
	{
		add_boton(new Boton(50, 50, 300, 220, "imagenes/TorreB.png", "imagenes/TorreN.png", std::bind(&VentanaTablero::poner_torre, this)));
		add_boton(new Boton(50, 50, 300, 140, "imagenes/ReinaB.png", "imagenes/ReinaN.png", std::bind(&VentanaTablero::poner_reina, this)));
		add_boton(new Boton(50, 50, 300, 80, "imagenes/AlfilB.png", "imagenes/AlfilN.png", std::bind(&VentanaTablero::poner_alfil, this)));
		add_boton(new Boton(50, 50, 300, 0, "imagenes/CaballoB.png", "imagenes/CaballoN.png", std::bind(&VentanaTablero::poner_caballo, this)));
		ventana_coronado = true;
	}

	
	if (tablero.mate(tablero.get_turno()) && !ventana_jaque)
	{
		add_boton(new Boton(150, 50, 250, -80, "imagenes/JaqueMate.png",
			(tablero.get_turno() == NEGRO) ? "imagenes/GananBlancas.png" : "imagenes/GananNegras.png", std::bind(&VentanaTablero::restart, this)));

		ventana_jaque = true;
		
	}

	if (tablero.ahogado(tablero.get_turno()) && !ventana_jaque)
	{
		add_boton(new Boton(150, 50, 250, -80, "imagenes/Ahogado.png",
			(tablero.get_turno() == NEGRO) ? "imagenes/GananBlancas.png" : "imagenes/GananNegras.png", std::bind(&VentanaTablero::restart, this)));

		ventana_jaque = true;

	}
	if (tablero.get_turno() == BLANCO)
	{
		turno = { "imagenes/JueganBlancas.png",0, -240, 300, 50 };
	}
	else
	{
		turno = { "imagenes/JueganNegras.png", 0, 320, 300, 50 };
	}
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
			iter->set_size(lado);
	}
	
	
	add_boton(new Boton(50, 50, 300, 300, "imagenes/restart.png", "imagenes/restartrojo.png", std::bind(&VentanaTablero::restart,this) ) ) ;
	
}

void VentanaTablero::restart() {
	tablero.restart();
	for (auto& iter : tablero.get_cuadricula()) {
		if (iter != nullptr)
			iter->set_size(lado);
	}
	for (int i = botones.size() -1 ; i >= 3; i--) {
		botones.erase(botones.begin() + i);
	}
	ventana_coronado = false;
	ventana_jaque = false;
}

void VentanaTablero::poner_torre()
{

	tablero.set_coronacion('R');
	for (int i = botones.size() - 1; i >= 3; i--) {
		botones.erase(botones.begin() + i);
	}
	ventana_coronado = false;
		
	
}

void VentanaTablero::poner_reina()
{
	tablero.set_coronacion('Q');
	for (int i = botones.size() - 1; i >= 3; i--) {
		botones.erase(botones.begin() + i);
	}
	ventana_coronado = false;

}

void VentanaTablero::poner_alfil()
{
	tablero.set_coronacion('B');
	for (int i = botones.size() - 1; i >= 3; i--) {
		botones.erase(botones.begin() + i);
	}
	ventana_coronado = false;
}

void VentanaTablero::poner_caballo()
{
	tablero.set_coronacion('N');
	for (int i = botones.size() - 1; i >= 3; i--) {
		botones.erase(botones.begin() + i);
	}
	ventana_coronado = false;

}

void VentanaTablero::eliminar_jaque()
{
	eliminar_boton();
	ventana_jaque = false;

}
