#include "Population.h"
#include <algorithm>

//Konstruktor
Population::Population()
{
	Size = 0;
}

//Konstruktor
Population::Population(int populationsize)
{
	Size = populationsize;
	Specimens.resize(Size);
}

//Dost�p do wielko�ci populacji
int Population::GetSize()
{
	return Size;
}

//Ustawienie wielo�ci populacji
void Population::SetSize(int size)
{
	Size = size;
	Specimens.resize(Size);
}

//Umieszczenie osobnika w populacji
void Population::AddSpecimen(Specimen S)
{
	Specimens.push_back(S);
	Size++;
}

//Umieszczenie osobnika w populacji
void Population::AddSpecimen(int index, Specimen s)
{
	Specimens[index] = s;
	Size++;
}

//Dost�p do okre�lonego osobnika w populacji
Specimen Population::GetSpecimenFromPopuation(int index)
{
	return Specimens[index];
}

//Losowanie rodzica do krzy�owania metod� rankingow�
Specimen Population::RankSelection()
{
	//Przedzia� losowania bed�cy sum� wszystkich ci�gu index�w wektora osobnik�w
	int range = Specimens.size() * (Specimens.size() + 1) / 2;
	//Wylosowana liczba z przedzia�u
	int pos = rand() % range;
	int sum = 0;

	for(int i = Specimens.size(); i > 0; i--)
	{
		sum = sum + i;
		if(pos < sum)
		{
			return Specimens[Specimens.size() - i];
		}
	}
}

//Losowanie rodzica do krzy�owania metod� turniejow�
Specimen Population::TournamentSelection()
{
	int const tournamentsize = 3;
	int contestantsamount;
	vector<Specimen> contestants, final;

	for(int i = 0; i < tournamentsize; i++)
	{
		contestantsamount = rand() % Specimens.size() / 2 + 1;
		contestants.resize(contestantsamount);
		
		for(int j = 0; j < contestantsamount; j++)
		{
			contestants[i] = GetSpecimenFromPopuation(rand() % Specimens.size());
		}
		final.push_back(*min_element(contestants.begin(), contestants.end(), Specimen::CompareSpecimens));
	}

	return *min_element(final.begin(), final.end(), Specimen::CompareSpecimens);
}

//Losowanie rodzica do krzy�owania metod� hybrydy metody rankingowej i turniejowej
Specimen Population::HybridSelection()
{
	int const tournamentsize = 3;
	int contestantsamount;
	vector<Specimen> contestants, final;

	for (int i = 0; i < tournamentsize; i++)
	{
		contestantsamount = rand() % Specimens.size() / 2 + 1;
		contestants.resize(contestantsamount);

		for (int j = 0; j < contestantsamount; j++)
		{
			contestants[i] = (RankSelection());
		}
		final.push_back(*min_element(contestants.begin(), contestants.end(), Specimen::CompareSpecimens));
	}

	return *min_element(final.begin(), final.end(), Specimen::CompareSpecimens);
}

//Sortowanie populacji rosn�co po koszcie �cie�ki
void Population::SortPopulation()
{
	sort(Specimens.begin(), Specimens.end(), Specimen::CompareSpecimens);
}

//Usuwa ostatniego osobnika z populacji
void Population::DeleteLast()
{
	Specimens.pop_back();
	Size--;
}