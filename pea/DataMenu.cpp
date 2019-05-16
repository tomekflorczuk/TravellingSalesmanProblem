#include "DataMenu.h"

int DataMenu::choice;
int DataMenu::size;

//Konstruktor
DataMenu::DataMenu()
{
}

//Destruktor
DataMenu::~DataMenu()
{
}

//Menu wyboru Ÿród³a macierzy
void DataMenu::ShowMenu()
{
	do
	{
		cout << "Wybierz:" << endl;
		cout << "1) Wczytaj z pliku" << endl;
		cout << "2) Generuj" << endl;
		cout << "3) Wyjscie" << endl;
		cin >> choice;
		switch (choice)
		{
		case(1):
			{
			Data::ReadFromFile();
			Data::ShowMatrix();
			Menu::ShowMenu();
			break;
			}
		case(2):
			{
			cout << "Podaj rozmiar macierzy: ";
			cin >> size;
			Data::Generate(size);
			Data::ShowMatrix();
			Menu::ShowMenu();
			break;
			}
		case(3):
			{
			exit(0);
			}
		default:
			{
			cout << "Podaj poprawna liczbe" << endl;
			break;
			}
		}
	} while (true);
}
