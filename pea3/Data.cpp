#include "Data.h"
#include "Specimen.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Ilo�� miast
int Data::Size;
//Miasto pocz�tkowe
int Data::StartingPoint;
//Wielko�� populacji
int Data::PopulationSize;
//Wsp�czynnik mutacji
float Data::MutationFactor;
//Wsp�czynnik krzy�owania
float Data::CrossoverFactor;
//Macierz odleg�o�ci
vector<vector<int>> Data::Matrix;
//Lista miast
vector<int> Data::Vertexes;

//Konstruktor
Data::Data()
{
	Size = 0;
	StartingPoint = 0;
	MutationFactor = 0.1;
	CrossoverFactor = 0.8;
}

//Wczytywanie danych z pliku
void Data::ReadFromFile()
{
	string FileName;
	bool Succeed = false;
	ifstream FileToOpen;
	//Wczytanie pliku
	do
	{
		cout << "Podaj nazwe pliku(z dopisikiem .txt)" << endl;
		cout << "Wpisz 0 aby wyjsc" << endl;
		cin >> FileName;

		FileToOpen.open(FileName);
		if (FileToOpen.is_open()) Succeed = true;
		else cout << "Blad wczytywania pliku" << endl;
		if (FileName == "0") exit(0);

	} while (Succeed != true);
	//Zapisanie ilo�ci miast
	FileToOpen >> Size;
	//Tworzenie macierzy odg�o�ci oraz uzupe�nianie listy miast
	Matrix.resize(Size);
	for (int i = 0; i < Size; i++)
	{
		if (i != 0) Vertexes.push_back(i);
		Matrix[i].resize(Size);
	}
	//Uzupe�nienie macierzy danymi
	for(int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			FileToOpen >> Matrix[i][j];
}

//Wypisanie wczytanych danych
void Data::ShowData()
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
			cout << setw(4) << Matrix[i][j];
		cout << endl;
	}
}

//Dost�p do kosztu przej�cia z miasta i do miasta j
int Data::GetCost(int i, int j)
{
	return Matrix[i][j];
}

//Obliczanie warto�ci �cie�ki
int Data::CalculateCost(vector<int> path)
{
	int cost = 0;

	cost += Matrix[StartingPoint][path[0]];

	for (int i = 0; i < path.size() - 1; i++)
	{
		cost += Matrix[path[i]][path[i + 1]];
	}
	cost += Matrix[path[path.size() - 1]][StartingPoint];

	return cost;
}

//Wygenerowania losowego rozwi�zania
vector<int> Data::GetRandomPath()
{
	vector<int> randompath;
	int pos;

	randompath.push_back(Vertexes[0]);

	for (int i = 1; i < Vertexes.size(); i++)
	{
		pos = rand() % randompath.size();
		randompath.insert(randompath.begin() + pos, Vertexes[i]);
	}

	return randompath;
}

//Dost�p do ilo�ci miast
int Data::GetSize()
{
	return Size;
}

//Dost�p do miasta startowego
int Data::GetStartingPoint()
{
	return StartingPoint;
}

//Dost�p do wsp�czynnika mutacji
float Data::GetMutationFactor()
{
	return MutationFactor;
}

//Ustawienie wsp�czynnika mutacji
void Data::SetMutationFactor(float mutationfactor)
{
	MutationFactor = mutationfactor;
}

//Dost�p do wsp�czynnika krzy�owania
float Data::GetCrossoverFactor()
{
	return CrossoverFactor;
}

//Ustawienie wsp�czynnika krzy�owania
void Data::SetCrossoverFactor(float crossoverfactor)
{
	CrossoverFactor = crossoverfactor;
}

//Dost�p do wielko�ci listy miast
int Data::GetVertexesSize()
{
	return Vertexes.size();
}

//Dost�p do wielko�ci populacji
int Data::GetPopulationSize()
{
	return PopulationSize;
}

//Ustawienie wielko�ci populacji
void Data::SetPopulationSize(int populationsize)
{
	PopulationSize = populationsize;
}

//Czyszczenie pami�ci
void Data::Clear()
{
	for (int i = 0; i < Size; i++)
		while (!Matrix[i].empty())
			Matrix[i].pop_back();
	while (!Matrix.empty())
		Matrix.pop_back();
	while (!Vertexes.empty())
		Vertexes.pop_back();
}