#include"Menu.h"

void Menu::dibuja()
{
	if (estado == 0)
	{
		pantallainicio.dibuja();
	}
	if (estado == 1)
	{
		tablero1.dibujafondo();
		tablero1.dibuja();
	}
	if (estado == 2)
	{
		tablero2.dibujafondo();
		tablero2.dibuja();
	}
	if (estado == 3)
	{
		menumusica.dibuja();
	}
	if (estado == 4)
	{
		exit(0);
	}

}
void Menu::detecta(int x, int y)
{
	if (estado == 0)
	{
		pantallainicio.detectar(x, y);
	}
	if (estado == 1)
	{
	tablero1.detectar(x, y);
	}
	if (estado == 2)
	{
	tablero2.detectar(x, y);
	}
	if (estado == 3)
	{
		menumusica.detectar(x, y);
	}
}
void Menu::clica(int x, int y)
{
	std::cout << x << ',' << y << std::endl;
	if (estado == 0)
	{
		pantallainicio.clicar(x, y, estado);
	}
	if (estado == 1)
	{
		tablero1.clicar(x, y,estado);
	}
	if (estado == 2)
	{
		tablero2.clicar(x, y, estado);
	}
	if (estado == 3)
	{
		menumusica.clicar(x, y, estado,muteado);
	}
}