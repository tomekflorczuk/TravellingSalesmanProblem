#include "Menu.h"

int Menu::choice;
long long int Menu::elapsed;
long long int Menu::frequency;
long long int Menu::start;

//Kontruktor
Menu::Menu()
{
	choice = 0;
}

//Destruktor
Menu::~Menu()
{
}

//Pomiar czasu
long long int Menu::read_QPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}

//Wyswietlanie menu
void Menu::ShowMenu()
{
	do
	{
		cout << "Wybierz:" << endl;
		cout << "1) Przeglad zupelny" << endl;
		cout << "2) Programowanie dynamiczne" << endl;
		cout << "3) Metoda podzialu i ogranicznen" << endl;
		cout << "4) Nowy plik" << endl;
		cout << "5) Wyjscie" << endl;
		cin >> choice;
		switch (choice)
		{
		//Przegl¹d zupe³ny
		case(1):
			{
			BF:BF();
			QueryPerformanceFrequency((LARGE_INTEGER *) & frequency);
			start = read_QPC();
			BF::BruteForce(BF::GetCurrentPoint());
			//BF::BruteForce(BF::GetStartingPoint(),BF::GetCurrentPoint());
			elapsed = read_QPC() - start;
			cout << "Time [s] = " << fixed << setprecision(6) << (float)elapsed / frequency << endl;
			//cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) / frequency << endl;
			BF::ShowResult();
			BF::Clear();
			break;
			}
		//Programowanie dynamiczne
		case(2):
			{
			DP:DP();
			QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
			start = read_QPC();
			//cout << "$" << DP::DynamicProgramming(1, Data::GetStartingPoint()) << endl;
			DP::DynamicProgramming(1, Data::GetStartingPoint(), DP::GetCost());
			elapsed = read_QPC() - start;
			cout << "Time [s] = " << fixed << setprecision(6) << (float)elapsed / frequency << endl;
			DP::ShowResult();
			DP::Clear();
			break;
			}
		//Podzia³ i ograniczenia
		case(3):
			{
			BB:BB();
			QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
			start = read_QPC();
			BB::BranchAndBound(BB::GetStartingPoint());
			//BB::BranchAndBound(BB::GetMatrix());
			elapsed = read_QPC() - start;
			cout << "Time [s] = " << fixed << setprecision(6) << (float)elapsed / frequency << endl;
			//cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) / frequency << endl;
			BB::ShowResult();
			BB::Clear();
			break;
			}
		//Wczytanie nowego pliku
		case(4):
			{
				Data::Clear();
				DataMenu::ShowMenu();
				break;
			}
		//Wyjœcie z programu
		case(5): 
		{
			Data::Clear();
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