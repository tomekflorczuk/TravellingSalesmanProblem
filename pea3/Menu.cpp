#include "Menu.h"
#include "Clock.h"
#include "Data.h"
#include "MutationMenu.h"
#include "SelectionMenu.h"
#include "Genetic.h"
#include <iostream>

using namespace std;

//Wybrana opcja z menu
int Menu::choice;

//Wyœwietlenie menu
void Menu::ShowMenu()
{
	do
	{
		cout << "Wybierz opcje." << endl;
		cout << "1) Wczytaj dane z pliku." << endl;
		cout << "2) Wprowadzenie kryterium stopu." << endl;
		cout << "3) Ustawienie wielkosci populacji poczatkowej." << endl;
		cout << "4) Ustawienie wspolczynnika mutacji." << endl;
		cout << "5) Ustawienie wspolczynnika krzyzowania." << endl;
		cout << "6) Wybor metody mutacji." << endl;
		cout << "7) Wybor metody selekcji" << endl;
		cout << "8) Uruchom algorytm." << endl;
		cout << "9) Wyjscie" << endl;

		cin >> choice;

		switch(choice)
		{
		//Wczytanie danych z pliku
		case(1):
		{
			if (Data::GetSize() != NULL)
				Data::Clear();
			Data::ReadFromFile();
			Data::ShowData();
			break;
		}
		//Wprowadzenie kryterium stopu
		case(2):
		{
			float duration;
			cout << "Podaj czas trwania algorytmu w sekundach: ";
			cin >> duration;
			Clock::SetDuration(duration);
			break;
		}
		//Ustawienie populacji pocz¹tkowej
		case(3):
		{
			int populationsize;
			
			cout << "Podaj wielkosc populacji: ";
			cin >> populationsize;
			Data::SetPopulationSize(populationsize);
			break;
		}
		//Ustawienie wspó³czynnika mutacji
		case(4):
		{
			float mutationfactor;

			cout << "Podaj wspolczynnik mutacji: ";
			cin >> mutationfactor;
			Data::SetMutationFactor(mutationfactor);
			break;
		}
		//Ustawienie wspó³czynnika krzy¿owania
		case(5):
		{
			float crossoverfactor;

			cout << "Podaj wspolczynnik krzyzowania: ";
			cin >> crossoverfactor;
			Data::SetCrossoverFactor(crossoverfactor);
			break;
		}
		//Wybór metody mutacji
		case(6):
		{
			MutationMenu::ShowMenu();
			break;
		}
		//Wybór metody selekcji
		case(7):
		{
			SelectionMenu::ShowMenu();
			break;
		}
		//Uruchomienie algorytmu
		case(8):
		{			
			if(Data::GetSize() == NULL)
			{
				cout << "Nie wczytano danych!" << endl;
				break;
			}
			if(Data::GetPopulationSize() == 0)
			{
				cout << "Nie podano wielkosci populacji!" << endl;
				break;
			}
			Genetic::Algorithm();
			Genetic::ShowResult();
			break;
		}
		//Wyjœcie
		case(9):
		{
			Data::Clear();
			exit(0);
		}
		default:
			cout << "Podano niepoprawna liczbe." << endl;
			break;
		}
	} while (true);
}