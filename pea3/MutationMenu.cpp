#include "MutationMenu.h"
#include <iostream>

using namespace std;

//Wybrany typ mutacji
int MutationMenu::mutationchoice;

//Konstruktor
MutationMenu::MutationMenu()
{
	mutationchoice = 1;
}

//Wyœwietlenie menu
void MutationMenu::ShowMenu()
{
	int choice;

	do
	{
		cout << "Wybierz typ mutacji." << endl;
		cout << "1) inversion" << endl;
		cout << "2) insertion" << endl;
		cout << "3) displacement" << endl;
		cout << "4) transposition" << endl;
		cout << "5) Wroc" << endl;

		cin >> choice;

		switch(choice)
		{
		case(1):
			{
			mutationchoice = 1;
			break;
			}
		case(2):
			{
			mutationchoice = 2;
			break;
			}
		case(3):
			{
			mutationchoice = 3;
			break;
			}
		case(4):
			{
			mutationchoice = 4;
			break;
			}
		case(5):
			break;
		default:
			cout << "Podano niepoprawna liczbe." << endl;
		}
	} while (choice < 1 || choice > 4);
}

//Dostêp do wybranego typu mutacji
int MutationMenu::GetMutationChoice()
{
	return mutationchoice;
}