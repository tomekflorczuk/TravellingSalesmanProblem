#include "Data.h"

using namespace std;

int Data::Size;
int Data::StartingPoint;
float Data::MaxCost;
int** Data::Matrix;
vector<int> Data::Vertexes;

//Konstruktor
Data::Data()
{
	Size = 0;
	StartingPoint = 0;
	MaxCost = 0;
}

//Czytanie danych z pliku
void Data::ReadFromFile()
{
	string FileName;
	int mincost = 0;
	bool Succeed = false;
	ifstream FileToOpen;

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

	FileToOpen >> Size;

	//Tworzenie macierzy odleg³oœci
	Matrix = new int* [Size];
	for (int i = 0; i < Size; i++)
	{
		if(i != 0)	Vertexes.push_back(i);	
		Matrix[i] = new int[Size];
	}

	//Uzupe³nianie macierzy odleg³oœci
	for (int i = 0; i < Size; i++)
	{
		int tempmaxcost = 0;
		int tempmincost = INT_MAX;
		for (int j = 0; j < Size; j++)
		{
			FileToOpen >> Matrix[i][j];
			if (Matrix[i][j] > tempmaxcost) tempmaxcost = Matrix[i][j];
			if (Matrix[i][j] < tempmincost && Matrix[i][j] != 0) tempmincost = Matrix[i][j];
		}
		MaxCost += tempmaxcost;
		mincost += tempmincost;
	}

	MaxCost -= mincost;
}

//Generowanie losowycy danych
void Data::Generate(int size)
{
	srand(time(nullptr));
	Size = size;

	//Tworzenie macierzy odleg³oœci
	Matrix = new int* [Size];
	for (int i = 0; i < Size; i++)
	{
		if(i != 0) Vertexes.push_back(i);
		Matrix[i] = new int[Size];
	}

	//Uzupe³nianie macierzy losowymi danymi
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
		{
			if (i == j) Matrix[i][j] = 0;
			else Matrix[i][j] = rand() % 100;
		}
}

//Dostêp do wielkoœci
int Data::GetSize()
{
	return Size;
}

//Dostêp do punktu pocz¹tkowego
int Data::GetStartingPoint()
{
	return StartingPoint;
}

//Dostêp do maksymalnego kosztu
float Data::GetMaxCost()
{
	return (float)MaxCost;
}

//Dostêp do kosztu przejœcia z miasta i do miasta j
int Data::GetCost(int i, int j)
{
	return Matrix[i][j];
}

//Obliczanie kosztu œcie¿ki
int Data::CalculateCost(vector<int> vertexes)
{
	int cost = 0;

	cost += Matrix[StartingPoint][vertexes[0]];

	for (int i = 0; i < vertexes.size() - 1; i++)
	{
		cost += Matrix[vertexes[i]][vertexes[i + 1]];
	}
	cost += Matrix[vertexes[vertexes.size() - 1]][StartingPoint];

	return cost;
}

//Dostêp do wierzcho³ków
vector<int>& Data::GetVertexes()
{
	return Vertexes;
}

//Generowanie losowego rozwi¹zania
vector<int> Data::RandomVertexes()
{
	vector<int> randomvertexes;
	int pos;

	randomvertexes.push_back(Vertexes[0]);

	for (int i = 1; i < Vertexes.size(); i++)
	{
		pos = rand() % randomvertexes.size();
		randomvertexes.insert(randomvertexes.begin() + pos, Vertexes[i]);
	}

	return randomvertexes;
}

//Wypisanie macierzy
void Data::ShowMatrix()
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
			cout << setw(5) << Matrix[i][j];
		cout << endl;
	}
}

//Wypisanie wierzcho³ków
void Data::ShowVertexes()
{
	for (int i = 0; i < Vertexes.size(); i++)
		cout << setw(3) << Vertexes[i];
	cout << endl;
}

//Czyszczenie pamiêci
void Data::Clear()
{
	for (int i = 0; i < Size; i++)
		delete[] Matrix[i];
	delete[] Matrix;

	Vertexes.clear();
}