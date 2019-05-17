#include "Specimen.h"
#include "Data.h"

//Konstuktor
Specimen::Specimen(vector<int> path)
{
	Path = path;
	Cost = Data::CalculateCost(Path);
}

//Kontruktor
Specimen::Specimen()
{
	Cost = 0;
}

//Dost�p do kosztu osobnika
int Specimen::GetCost() const
{
	return Cost;
}

//Dost�p do �cie�ki osobnika
vector<int> Specimen::GetPath() const
{
	return Path;
}

//Ustawienie �cie�ki osobnika
void Specimen::SetPath(vector<int> path)
{
	Path = path;
	Cost = Data::CalculateCost(Path);
}

//Por�wnanie osobnik�w
int Specimen::CompareSpecimens(Specimen S1, Specimen S2)
{
	if (S1.Cost >= S2.Cost)
		return false;

	if (S1.Cost < S2.Cost)
		return true;
}