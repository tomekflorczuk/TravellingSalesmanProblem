#include "Menu.h"

using namespace std;

int Menu::choice;

//Konstruktor
Menu::Menu()
{
	choice = 0;
}

//Wyœwietlenie menu
void Menu::ShowMenu()
{
	do
	{
		cout << "Wybierz opcje" << endl;
		cout << "1) Wczytanie danych z pliku" << endl;
		cout << "2) Generuj losowe dane" << endl;
		cout << "3) Wprowadzenie kryterium stopu" << endl;
		cout << "4) Wlaczenie/wylaczenie dywersyfikacji" << endl;
		cout << "5) Wybor sasiedztwa" << endl;
		cout << "6) Uruchom algorytm symulowanego wyzarzania" << endl;
		cout << "7) Uruchom algorytm tabu search" << endl;
		cout << "8) Wyjscie" << endl;
		cin >> choice;

		switch (choice)
		{
		//Wczytywanie danych z pliku
		case(1):
		{			
			if(Data::GetSize() != NULL) Data::Clear();
			Data();
			Data::ReadFromFile();
			//Data::ShowMatrix();
			break;
		}
		//Generowanie losowych danych
		case(2):
		{
			int size;

			cout << "Podaj wymiar macierzy:";
			cin >> size;

			if(Data::GetSize() != NULL) Data::Clear();
			Data();
			Data::Generate(size);
			//Data::ShowMatrix();
			break;
		}	
		//Kryterium stopu
		case(3):
		{
			float duration;

			cout << "Podaj czas dzialania algorytmu (w sekundach):";
			cin >> duration;
			Clock::SetDuration(duration);
			break;
		}
		//W³¹czenie/wy³¹czenie dywersyfikacji
		case(4):
		{
			TS::ToogleDiversification();
			if (TS::GetDiversification() == true) cout << "Wlaczono dywersyfikacje" << endl;
			else cout << "Wylaczono dywesyfikiacje" << endl;
			break;
		}
		//Wybór s¹siedztwa
		case(5):
		{
			NeighbourhoodMenu::ShowMenu();
			break;
		}
		//Uruchomienie algorytmu symulowanego wy¿arzania
		case(6):
		{
			if(Data::GetSize() == NULL)
			{
				cout << "Nie zaladowano pliku!" << endl;
				cout << endl;
				break;
			}
			SA::Algorithm();
			SA::ShowResult();
			break;
		}
		//Uruchomienie algorymtu tabu search
		case(7):
		{
			if (Data::GetSize() == NULL)
			{
				cout << "Nie zaladowano pliku!" << endl;
				cout << endl;
				break;
			}
			TS::Algorithm();
			TS::ShowResult();
			break;
		}
		//Wyjœcie z programu
		case(8):
		{
			Data::Clear();
			exit(0);
		}
		default:
		{
			cout << "Podaj prawidlowa liczbe!" << endl;
			break;
		}
		}
	} while (true);
}