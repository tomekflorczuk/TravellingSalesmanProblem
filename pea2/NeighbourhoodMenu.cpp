#include "NeighbourhoodMenu.h"

using namespace std;

int NeighbourhoodMenu::neighbourhoodchoice;

//Konstruktor
NeighbourhoodMenu::NeighbourhoodMenu()
{
	neighbourhoodchoice = 1;
}

//Dost�p do typu s�siedztwa
int NeighbourhoodMenu::GetNeighbourhoodChoice()
{
	return neighbourhoodchoice;
}

//Wy�wietlenie menu wyboru s�siedztwa
void NeighbourhoodMenu::ShowMenu()
{
	int choice;
	do
	{
		cout << "Wybierz rodzaj sasiedztwa:" << endl;
		cout << "1) Typu insert" << endl;
		cout << "2) Typu swap" << endl;
		cout << "3) Typu invert" << endl;
		cout << "4) Wroc" << endl;
		cin >> choice;

		switch(choice)
		{
		case(1):
			{
			neighbourhoodchoice = choice;
			break;
			}
		case(2):
			{
			neighbourhoodchoice = choice;
			break;
			}
		case(3):
			{
			neighbourhoodchoice = choice;
			break;
			}
		case(4):
			{
			break;
			}
		default:
			{
			cout << "Podaj prawdilowa liczbe!" << endl;
			cout << endl;
			break;
			}
		}
	} while (choice < 1 || choice > 4);
}