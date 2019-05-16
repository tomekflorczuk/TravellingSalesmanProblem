#include "Menu.h"
#include "NeighbourhoodMenu.h"
#include "Clock.h"

void main()
{
	srand(time(nullptr));
	Clock();
	NeighbourhoodMenu();
	Menu::ShowMenu();
}