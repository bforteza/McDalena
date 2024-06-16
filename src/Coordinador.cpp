#include "Coordinador.h"

void Coordinador::dibuja()
{
	if (actual != nullptr) {
		actual->dibuja();
		Menu.anima();
		Integrantes.anima();
	}
}

void Coordinador::detecta(GLdouble x, GLdouble y)
{
	if (actual != nullptr) {
		actual->detecta(x,y);
	}
}

void Coordinador::click()
{
	if (actual != nullptr) {
		actual->click();
	}
}

void Coordinador::set_speedchess()
{
	actual = &speedchess;
}

void Coordinador::set_unicopeon()
{
	actual = &unicopeon;
}

void Coordinador::set_menu()
{
	actual = &Menu;
}
void Coordinador::set_menumusica()
{
	actual = &MenuMusica;
}
void Coordinador::set_salir()
{
	exit(0);
}
void Coordinador::set_integrantes()
{
	actual = &Integrantes;
}
void Coordinador::set_butterflies()
{
	if(muteado==false)
	ETSIDI::playMusica(cancion1, true);
}
void Coordinador::set_leapoffaith()
{
	if (muteado == false)
	ETSIDI::playMusica(cancion2, true);
}
void Coordinador::set_livefreeordie()
{
	if (muteado == false)
	ETSIDI::playMusica(cancion3, true);
}
void Coordinador::set_mute()
{
	muteado = true;
	Integrantes.set_mute(muteado);
	MenuMusica.set_mute(muteado);
	unicopeon.set_mute(muteado);
	speedchess.set_mute(muteado);
	Menu.set_mute(muteado);

	Integrantes.mutear();
	MenuMusica.mutear();
	unicopeon.mutear();
	speedchess.mutear();
	Menu.mutear();
	ETSIDI::stopMusica();
}
void Coordinador::set_unmute()
{
	muteado = false;
	Integrantes.set_mute(muteado);
	MenuMusica.set_mute(muteado);
	unicopeon.set_mute(muteado);
	speedchess.set_mute(muteado);
	Menu.set_mute(muteado);

	Integrantes.mutear();
	MenuMusica.mutear();
	unicopeon.mutear();
	speedchess.mutear();
	Menu.mutear();
}
Coordinador::Coordinador(GLdouble _ancho, GLdouble _alto) :
	ancho(_ancho), alto(_alto) {

	actual = &Menu;
	Menu.add_animacion(new Animacion("imagenes/pixelchessanimacion.png", 10, 1, 100, 0, 240, 700, 90));

	Menu.add_boton(new Boton(600, 80, 0, 120, "imagenes/UnpeonNegro.png", "imagenes/UnpeonBlanco.png", 1, std::bind(&Coordinador::set_unicopeon, this)));
	Menu.add_boton(new Boton(350, 80, 0, 0, "imagenes/SpeedchessNegro.png", "imagenes/SpeedchessBlanco.png", 1, std::bind(&Coordinador::set_speedchess, this)));
	Menu.add_boton(new Boton(250, 80, 0, -120, "imagenes/MenuMusicaNegro.png", "imagenes/MenuMusicaBlanco.png", 1, std::bind(&Coordinador::set_menumusica, this)));
	Menu.add_boton(new Boton(200, 80, 0, -240, "imagenes/SalirNegro.png", "imagenes/SalirBlanco.png", 1, std::bind(&Coordinador::set_salir, this)));
	Menu.add_boton(new Boton(100, 100, 240, -240, "imagenes/Panda1.png", "imagenes/Panda2.png", 4, std::bind(&Coordinador::set_integrantes, this)));
	//Menu.add_boton(new Boton(700, 90, 0, 240, "imagenes/pixelchess.png", "imagenes/pixelchess.png", 1, nullptr));

	speedchess.add_boton(new Boton(100, 100, -300, 300, "imagenes/Volver.png", "imagenes/PreVolver.png", 2, std::bind(&Coordinador::set_menu, this)));
	unicopeon.add_boton(new Boton(100, 100, -300, 300, "imagenes/Volver.png", "imagenes/PreVolver.png", 2, std::bind(&Coordinador::set_menu, this)));

	MenuMusica.add_boton(new Boton(100, 100, -300, 300, "imagenes/Volver.png", "imagenes/PreVolver.png", 1, std::bind(&Coordinador::set_menu, this)));
	MenuMusica.add_boton(new Boton(250, 50, -10, 140, "imagenes/ButterfliesNegro.png", "imagenes/ButterfliesAzul.png", 0, std::bind(&Coordinador::set_butterflies, this)));
	MenuMusica.add_boton(new Boton(250, 50, -10, 0, "imagenes/LeapoffaithNegro.png", "imagenes/LeapoffaithAzul.png", 0, std::bind(&Coordinador::set_leapoffaith, this)));
	MenuMusica.add_boton(new Boton(280, 50, -10, -140, "imagenes/LivefreeordieNegro.png", "imagenes/LivefreeordieAzul.png", 0, std::bind(&Coordinador::set_livefreeordie, this)));
	MenuMusica.add_boton(new BotonEnclavado(100, 100, 260, 260, "imagenes/NoMute.png", "imagenes/MuteAzul.png", "imagenes/Mute.png", 5, std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));



	Integrantes.add_boton(new Boton(100, 100, -300, 300, "imagenes/Volver.png", "imagenes/PreVolver.png", 1, std::bind(&Coordinador::set_menu, this)));
	Integrantes.add_boton(new Boton(350, 50, -10, 240, "imagenes/Tomeu.png", "imagenes/TomeuAzul.png", 9, std::bind(&Coordinador::activa_vader, this)));
	Integrantes.add_boton(new Boton(250, 50, -10, 100, "imagenes/Mario.png", "imagenes/MarioRojo.png", 9, std::bind(&Coordinador::activa_vader, this)));
	Integrantes.add_boton(new Boton(250, 50, -10, -40, "imagenes/David.png", "imagenes/DavidVerde.png", 9, std::bind(&Coordinador::activa_vader, this)));

	Integrantes.add_animacion(new AnimacionMovil("imagenes/Xwing.png", 1, 8, 100, -400, 240, 80, 80));

	Integrantes.add_animacion(new Animacion("imagenes/Sarlacc.png", 20, 1, 100, 0, -205, 300, 300));

}