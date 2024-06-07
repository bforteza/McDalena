#include "Coordinador.h"

void Coordinador::dibuja()
{
	if (actual != nullptr) {
		actual->dibuja();
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
	ETSIDI::stopMusica();
}
void Coordinador::set_unmute()
{
	muteado = false;
}
Coordinador::Coordinador(GLdouble _ancho, GLdouble _alto) :
	ancho(_ancho), alto(_alto) {
	
	actual = &Menu;
	
	Menu.add_boton(new Boton(600, 80, 0, 120, "bin/imagenes/UnpeonNegro.png", "bin/imagenes/UnpeonBlanco.png", std::bind(&Coordinador::set_unicopeon, this)));
	Menu.add_boton(new Boton(350, 80, 0, 0, "bin/imagenes/SpeedchessNegro.png", "bin/imagenes/SpeedchessBlanco.png", std::bind(&Coordinador::set_speedchess, this)));
	Menu.add_boton(new Boton(250, 80, 0, -120, "bin/imagenes/MenuMusicaNegro.png", "bin/imagenes/MenuMusicaBlanco.png", std::bind(&Coordinador::set_menumusica, this)));
	Menu.add_boton(new Boton(200, 80, 0, -240, "bin/imagenes/SalirNegro.png", "bin/imagenes/SalirBlanco.png", std::bind(&Coordinador::set_salir, this)));
	Menu.add_boton(new Boton(100, 100, 240, -240, "bin/imagenes/Panda1.png", "bin/imagenes/Panda2.png", std::bind(&Coordinador::set_integrantes, this)));
	Menu.add_boton(new Boton(700, 90, 0, 240, "bin/imagenes/pixelchess.png", "bin/imagenes/pixelchess.png", nullptr));
	Menu.add_boton(new BotonEnclavado(100, 100, -240, -240, "bin/imagenes/NoMute.png", "bin/imagenes/MuteAzul.png", "bin/imagenes/Mute.png", std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));

	speedchess.add_boton(new Boton(100, 100, -300, 300, "bin/imagenes/Volver.png", "bin/imagenes/PreVolver.png", std::bind(&Coordinador::set_menu, this)));
	speedchess.add_boton(new BotonEnclavado(100, 100, -240, -260, "bin/imagenes/NoMute.png", "bin/imagenes/MuteAzul.png", "bin/imagenes/Mute.png", std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));
	unicopeon.add_boton(new Boton(100, 100, -300, 300, "bin/imagenes/Volver.png", "bin/imagenes/PreVolver.png", std::bind(&Coordinador::set_menu, this)));
	unicopeon.add_boton(new BotonEnclavado(100, 100, -240, -260, "bin/imagenes/NoMute.png", "bin/imagenes/MuteAzul.png", "bin/imagenes/Mute.png", std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));
	
	MenuMusica.add_boton(new Boton(100, 100, -300, 300, "bin/imagenes/Volver.png", "bin/imagenes/PreVolver.png", std::bind(&Coordinador::set_menu, this)));
	MenuMusica.add_boton(new Boton(250, 50, -10, 140, "bin/imagenes/ButterfliesNegro.png", "bin/imagenes/ButterfliesAzul.png", std::bind(&Coordinador::set_butterflies, this)));
	MenuMusica.add_boton(new Boton(250, 50, -10, 0, "bin/imagenes/LeapoffaithNegro.png", "bin/imagenes/LeapoffaithAzul.png", std::bind(&Coordinador::set_leapoffaith, this)));
	MenuMusica.add_boton(new Boton(280, 50, -10, -140, "bin/imagenes/LivefreeordieNegro.png", "bin/imagenes/LivefreeordieAzul.png", std::bind(&Coordinador::set_livefreeordie, this)));
	MenuMusica.add_boton(new BotonEnclavado(100, 100, 260, 260, "bin/imagenes/NoMute.png","bin/imagenes/MuteAzul.png", "bin/imagenes/Mute.png", std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));

	Integrantes.add_boton(new Boton(100, 100, -300, 300, "bin/imagenes/Volver.png", "bin/imagenes/PreVolver.png", std::bind(&Coordinador::set_menu, this)));
	Integrantes.add_boton(new Boton(350, 50, -10, 240, "bin/imagenes/Tomeu.png", "bin/imagenes/Tomeu.png", nullptr));
	Integrantes.add_boton(new Boton(250, 50, -10, 100, "bin/imagenes/Mario.png", "bin/imagenes/Mario.png",nullptr));
	Integrantes.add_boton(new Boton(250, 50, -10, -40, "bin/imagenes/David.png", "bin/imagenes/David.png", nullptr));
	Integrantes.add_boton(new Boton(280, 50, -10, -180, "bin/imagenes/Matias.png", "bin/imagenes/Matias.png",nullptr));
	Integrantes.add_boton(new BotonEnclavado(100, 100, 260, 260, "bin/imagenes/NoMute.png", "bin/imagenes/MuteAzul.png", "bin/imagenes/Mute.png", std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));
	
Integrantes.add_boton(new BotonEnclavado(100, 100, 260, 260, "bin/imagenes/NoMute.png", "bin/imagenes/MuteAzul.png", "bin/imagenes/Mute.png", std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));
 }