#include <ctime>
#include "Data.h"
#include "Clock.h"
#include "MutationMenu.h"
#include "SelectionMenu.h"
#include "Menu.h"

void main()
{
	srand(time(nullptr));
	Data();
	Clock();
	MutationMenu();
	SelectionMenu();
	Menu::ShowMenu();
}