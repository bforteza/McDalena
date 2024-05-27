#include"Menu.h"

void Menu::dibuja()
{
	if (estado == 1)
	{
		tablero1.dibujafondo();
		tablero1.print();
	}
	if (estado == 0)
	{
		pantallainicio.dibuja();
	}

}
void Menu::detecta(int x, int y)
{
	if (estado == 1)
	{
	tablero1.detectar(x, y);
	}
	
	if (estado == 0)
	{
		pantallainicio.detectar(x, y);
	}
}
void Menu::clica(int x, int y)
{
	if (estado == 1)
	{
		tablero1.clicar(x, y);
	}
	if (estado == 0)
	{
		pantallainicio.clicar(x, y,estado);
	}
}