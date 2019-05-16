#pragma once
#include "Specimen.h"
#include <vector>

using namespace std;

class Population
{
	int Size;
	vector<Specimen> Specimens;
public:
	Population();
	Population(int populationsize);
	int GetSize();
	void SetSize(int size);
	void AddSpecimen(Specimen S);
	void AddSpecimen(int index, Specimen s);
	Specimen GetSpecimenFromPopuation(int index);
	Specimen RankSelection();
	Specimen TournamentSelection();
	Specimen HybridSelection();
	void SortPopulation();
	void DeleteLast();
};