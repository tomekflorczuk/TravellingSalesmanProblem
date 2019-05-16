#include "SelectionMenu.h"
#include <iostream>

using namespace std;

//Wybrany typ selekcji
int SelectionMenu::selectionchoice;

//Konstruktor
SelectionMenu::SelectionMenu()
{
	selectionchoice = 1;
}

//Wyœwietlenie menu
void SelectionMenu::ShowMenu()
{
	int choice;

	do
	{
		cout << "Wybierz typ selekcji." << endl;
		cout << "1) Metoda rankingowa." << endl;
		cout << "2) Metoda turniejowa." << endl;
		cout << "3) Hybryda metody rankingowej i turniejowej." << endl;
		cout << "4) Wroc" << endl;

		cin >> choice;

		switch(choice)
		{
		case(1):
		{
			selectionchoice = 1;
			break;
		}
		case(2):
		{
			selectionchoice = 2;
			break;
		}
		case(3):
		{
			selectionchoice = 3;
			break;
		}
		case(4):

			break;
		default:
			cout << "Podano niepoprawna liczbe." << endl;
		}
	} while (choice < 1 || choice > 3);
}

//Dostêp do wyboru selekcji
int SelectionMenu::GetSelectionChoice()
{
	return selectionchoice;
}