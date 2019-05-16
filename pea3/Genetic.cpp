#include "Genetic.h"
#include "Data.h"
#include "Specimen.h"
#include "Clock.h"
#include "Mutation.h"
#include "Crossover.h"
#include "Population.h"
#include "SelectionMenu.h"
#include <iomanip>
#include <fstream>
#include <windows.h>

//Najlepsze znalezione rozwi¹zanie
Specimen Genetic::BestSolution;

//G³owny algorytm genetyczny
void Genetic::Algorithm()
{
	//Zmienne zapisu danych do pliku
	ofstream DataFile;
	DataFile.open("ag.csv");
	//Zmienne do obs³ugi czasu
	long long int frequency = Clock::GetFrequency();
	float duration, timestamp = 0;
	//Zmienne przechowuj¹ce rodzicó i dzieci
	Specimen child1, child2, parent1, parent2;
	//Utworzenie populacji pocz¹tkowej
	Population mainpopulation;
	for (int i = 0; i < Data::GetPopulationSize(); i++)
	{
		Specimen S(Data::GetRandomPath());
		mainpopulation.AddSpecimen(S);
	}
	//Sortowanie populacji
	mainpopulation.SortPopulation();
	//Ustalenie pocz¹tkowego najlepszego rozwi¹zania
	BestSolution = mainpopulation.GetSpecimenFromPopuation(0);
	//Start zegara
	DataFile << "minimalny koszt; czas dzia³ania algorytmu[s]" << endl;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	Clock::SetStart(Clock::read_QPC());

	//G³ówny algorytm
	do
	{
		//Wyznaczanie nowej populacji
		Population newpopulation;
		for (int k = 0; k < ceil(Data::GetPopulationSize() / 2); k++)
		{		
			//Selekcja rodziców
			switch (SelectionMenu::GetSelectionChoice())
			{
				//Metoda rankingowa
				case(1):
				{
					parent1 = mainpopulation.RankSelection();
					parent2 = mainpopulation.RankSelection();
					break;
				}
				//Metoda turniejowa
				case(2):
				{
					parent1 = mainpopulation.TournamentSelection();
					parent2 = mainpopulation.TournamentSelection();
					break;
				}
				//Hybryda
				case(3):
				{
					parent1 = mainpopulation.HybridSelection();
					parent2 = mainpopulation.HybridSelection();
					break;
				}
			}
			//Krzy¿owanie
			if (Random() < Data::GetCrossoverFactor())
			{
				child1.SetPath(Crossover::Cross(parent1.GetPath(), parent2.GetPath()));
				//Mutacja
				if (Random() < Data::GetMutationFactor())
					Mutation::Mutate(child1.GetPath());
				newpopulation.AddSpecimen(child1);

				child2.SetPath(Crossover::Cross(parent2.GetPath(), parent1.GetPath()));
				//Mutacja
				if (Random() < Data::GetMutationFactor())
					Mutation::Mutate(child2.GetPath());				 
				newpopulation.AddSpecimen(child2);
			}
			else
			{
				newpopulation.AddSpecimen(parent1);
				newpopulation.AddSpecimen(parent2);
			}
		}
		//Sortowanie populacji
		newpopulation.SortPopulation();
		//Je¿eli nieparzysta wielkoœæ populacji, usuwa ostatniego(najgorszego) osobnika z populacji by uregulowaæ wielkoœæ populacji
		if(newpopulation.GetSize() > Data::GetPopulationSize())
			newpopulation.DeleteLast();
		//Nowa populacja staje siê g³ówn¹
		mainpopulation = newpopulation;
		//Zapisanie danych o najlepszym znalezionym osobniku
		if (BestSolution.GetCost() > mainpopulation.GetSpecimenFromPopuation(0).GetCost())
		{
			BestSolution = mainpopulation.GetSpecimenFromPopuation(0);
		}
		//Pobranie czasu
		Clock::SetElapsed(Clock::read_QPC() - Clock::GetStart());
		duration = (float)Clock::GetElapsed() / frequency;
		//Zapisywanie danych do pliku co okreœlony czas
		if (duration > timestamp)
		{
			DataFile << BestSolution.GetCost() << ";" << duration << endl;
			timestamp += 0.5;
		}
	} while (duration < Clock::GetDuration());

	DataFile.close();
}

//Losowanie liczby z przedzia³u <0,1>
float Genetic::Random()
{
	return (float)rand() / RAND_MAX;
}

//Wyœwietlenie wyniku
void Genetic::ShowResult()
{
	cout << Data::GetStartingPoint() << "->";
	for(int i = 0; i < BestSolution.GetPath().size(); i++)
		cout << BestSolution.GetPath()[i] << setw(2) << "->";
	cout << Data::GetStartingPoint() << endl;
	cout << "$" << BestSolution.GetCost() << endl;
}