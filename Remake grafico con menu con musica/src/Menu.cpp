#include"Menu.h"
#pragma once

void Menu::set()
{
	if (estado == 0) {
		PantallaInicio.add_boton({ 1200,1200,40,300,"bin/imagenes/pixelchess.png","bin/imagenes/pixelchess.png",0 });
		PantallaInicio.add_boton({ 500,80,-10,100,"bin/imagenes/UnpeonNegro.png","bin/imagenes/UnpeonBlanco.png",1 });
		PantallaInicio.add_boton({ 300,80,-10,-20,"bin/imagenes/SpeedchessNegro.png","bin/imagenes/SpeedchessBlanco.png",2 });
		PantallaInicio.add_boton({ 200,60,-10,-140,"bin/imagenes/MenumusicaNegro.png","bin/imagenes/MenumusicaBlanco.png",3 });
		PantallaInicio.add_boton({ 200,60,-10,-260,"bin/imagenes/SalirNegro.png","bin/imagenes/SalirBlanco.png",4 });
	}
	else if (estado == 1) {

		UnPeon.add_boton({ 100,100,-320,280,"bin/imagenes/Volver.png","bin/imagenes/PreVolver.png",0 });

	}
	else if (estado == 2) {

		SpeedChess.add_boton({ 100,100,-320,280,"bin/imagenes/Volver.png","bin/imagenes/PreVolver.png",0 });

	}
	else if (estado == 3) {

		MenuMusica.add_boton({ 100,100,-350,300,"bin/imagenes/Volver.png","bin/imagenes/PreVolver.png",0 });
		MenuMusica.add_boton({ 300,80,-20,100,"bin/imagenes/LeapoffaithNegro.png","bin/imagenes/LeapoffaithAzul.png",10 });
		MenuMusica.add_boton({ 300,80,-20,-20,"bin/imagenes/LivefreeordieNegro.png","bin/imagenes/LivefreeordieAzul.png",11 });
		MenuMusica.add_boton({ 300,80,-20,-140,"bin/imagenes/ButterfliesNegro.png","bin/imagenes/ButterfliesAzul.png",12 });
		MenuMusica.add_boton({ 100,100,300,300,"bin/imagenes/NoMute.png","bin/imagenes/Mute.png",13 });
	}
	else if (estado == 10) {

		marcamusica = 1;
		
		estado = 3;
	}
	else if (estado == 11) {

		marcamusica = 2;
		
		estado = 3;
	}
	else if (estado == 12) {

		marcamusica = 3;
		
		estado = 3;

	}
	else if (estado == 13) {

		marcamusica = 0;

		estado = 3;

	}
}
void Menu::dibuja()
{
	if (estado == 0)
	{
		
		
		PantallaInicio.dibuja();

		/*Boton(const GLdouble & Ancho, const GLdouble & Alto
			const GLdouble & x, const GLdouble & y,
			std::string Path1, std::string Path2,
			void (*func)());*/
	}
	if (estado == 1)
	{
		UnPeon.dibuja();
	}
	if (estado == 2)
	{
		SpeedChess.dibuja();
	}
	if (estado == 3)
	{	
		MenuMusica.dibuja();
		
	}
	if (estado == 4)
	{
		exit(0);
	}
	if (marcamusica == 1  && estado == 10)
	{
		ETSIDI::playMusica("bin/sonidos/LeapOfFaith.mp3", true);
	}
	if (marcamusica == 2 && estado == 11)
	{
		ETSIDI::playMusica("bin/sonidos/LiveFreeOrDie.mp3", true);
	}
	if (marcamusica == 3 && estado == 12)
	{
		ETSIDI::playMusica("bin/sonidos/Butterflies.mp3", true);
	}
	std::cout << marcamusica << std::endl;
}
void Menu::detecta(int x, int y)
{
	if (estado == 0)
	{
		PantallaInicio.detecta(x, y);
	}
	if (estado == 1)
	{
		UnPeon.detecta(x, y);
	}
	if (estado == 2)
	{
		SpeedChess.detecta(x, y);
	}
	if (estado == 3)
	{
		MenuMusica.detecta(x, y);
	}
}
void Menu::clica(int x, int y)
{
	
	if (estado == 0)
	{
		PantallaInicio.click(x, y,estado);
		std::cout << estado << std::endl;
			//tablero.clicar(x_raton, y_raton);
	}
	if (estado == 1)
	{
		UnPeon.click(x, y, estado);
	}
	if (estado == 2)
	{
		SpeedChess.click(x, y, estado);
	}
	if (estado == 3)
	{
		MenuMusica.click(x, y, estado);
	}
}