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
	
	Menu.add_boton(new Boton(600, 80, 0, 120, "imagenes/UnpeonNegro.png", "imagenes/UnpeonBlanco.png",1, std::bind(&Coordinador::set_unicopeon, this)));
	Menu.add_boton(new Boton(350, 80, 0, 0, "imagenes/SpeedchessNegro.png", "imagenes/SpeedchessBlanco.png", 1, std::bind(&Coordinador::set_speedchess, this)));
	Menu.add_boton(new Boton(250, 80, 0, -120, "imagenes/MenuMusicaNegro.png", "imagenes/MenuMusicaBlanco.png", 1, std::bind(&Coordinador::set_menumusica, this)));
	Menu.add_boton(new Boton(200, 80, 0, -240, "imagenes/SalirNegro.png", "imagenes/SalirBlanco.png", 1, std::bind(&Coordinador::set_salir, this)));
	Menu.add_boton(new Boton(100, 100, 240, -240, "imagenes/Panda1.png", "imagenes/Panda2.png", 4, std::bind(&Coordinador::set_integrantes, this)));
	Menu.add_boton(new Boton(700, 90, 0, 240, "imagenes/pixelchess.png", "imagenes/pixelchess.png", 1, nullptr));
	Menu.add_boton(new BotonEnclavado(100, 100, -240, -240, "imagenes/NoMute.png", "imagenes/MuteAzul.png", "imagenes/Mute.png", 5, std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));

	speedchess.add_boton(new Boton(100, 100, -300, 300, "imagenes/Volver.png", "imagenes/PreVolver.png",2, std::bind(&Coordinador::set_menu, this)));
	speedchess.add_boton(new BotonEnclavado(100, 100, -240, -260, "imagenes/NoMute.png", "imagenes/MuteAzul.png", "imagenes/Mute.png", 5, std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));
	unicopeon.add_boton(new Boton(100, 100, -300, 300, "imagenes/Volver.png", "imagenes/PreVolver.png",2, std::bind(&Coordinador::set_menu, this)));
	unicopeon.add_boton(new BotonEnclavado(100, 100, -240, -260, "imagenes/NoMute.png", "imagenes/MuteAzul.png", "imagenes/Mute.png", 5, std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));
	
	MenuMusica.add_boton(new Boton(100, 100, -300, 300, "imagenes/Volver.png", "imagenes/PreVolver.png", 0,std::bind(&Coordinador::set_menu, this)));
	MenuMusica.add_boton(new Boton(250, 50, -10, 140, "imagenes/ButterfliesNegro.png", "imagenes/ButterfliesAzul.png", 0, std::bind(&Coordinador::set_butterflies, this)));
	MenuMusica.add_boton(new Boton(250, 50, -10, 0, "imagenes/LeapoffaithNegro.png", "imagenes/LeapoffaithAzul.png", 0, std::bind(&Coordinador::set_leapoffaith, this)));
	MenuMusica.add_boton(new Boton(280, 50, -10, -140, "imagenes/LivefreeordieNegro.png", "imagenes/LivefreeordieAzul.png", 0, std::bind(&Coordinador::set_livefreeordie, this)));
	MenuMusica.add_boton(new BotonEnclavado(100, 100, 260, 260, "imagenes/NoMute.png","imagenes/MuteAzul.png", "imagenes/Mute.png",5, std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));

	Integrantes.add_boton(new Boton(100, 100, -300, 300, "imagenes/Volver.png", "imagenes/PreVolver.png", 1, std::bind(&Coordinador::set_menu, this)));
	Integrantes.add_boton(new Boton(350, 50, -10, 240, "imagenes/Tomeu.png", "imagenes/Tomeu.png", 4, nullptr));
	Integrantes.add_boton(new Boton(250, 50, -10, 100, "imagenes/Mario.png", "imagenes/Mario.png", 4, nullptr));
	Integrantes.add_boton(new Boton(250, 50, -10, -40, "imagenes/David.png", "imagenes/David.png", 4, nullptr));

	Integrantes.add_boton(new BotonEnclavado(100, 100, 260, 260, "imagenes/NoMute.png", "imagenes/MuteAzul.png", "imagenes/Mute.png", 5, std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));
	
Integrantes.add_boton(new BotonEnclavado(100, 100, 260, 260, "imagenes/NoMute.png", "imagenes/MuteAzul.png", "imagenes/Mute.png", 5, std::bind(&Coordinador::set_mute, this), std::bind(&Coordinador::set_unmute, this)));
 }