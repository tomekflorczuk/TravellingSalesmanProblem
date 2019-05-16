#include "Data.h"

using namespace std;

int Data::Size;
int Data::StartingPoint;
int** Data::Matrix;

//Konstruktor
Data::Data()
{
	Size = 0;
	StartingPoint = 0;
}

//Destruktor
Data::~Data()
{
}

//Czytanie danych z pliku
void Data::ReadFromFile()
{
	string FileName;
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

	//Ilo�� miast
	FileToOpen >> Size;
	
	//Generowanie macierzy odleg�o�ci
	Matrix = new int * [Size];
	for(int i = 0 ; i < Size ; i++)
	{
		Matrix[i] = new int[Size];
	}

	//Uzupe�nianie macierzy danymi z pliku
	for(int i = 0 ; i < Size ; i++)
	{
		for(int j = 0 ; j < Size ; j++)
		{
			FileToOpen >> Matrix[i][j];
		}
	}
}

//Generowanie losowych danych
void Data::Generate(int size)
{
	srand(time(nullptr));

	Size = size;

	//Generowanie macierzy odleg�o�ci
	Matrix = new int *[Size];
	for (int i = 0; i < Size; i++)
	{
		Matrix[i] = new int[Size];
	}

	//Uzupe�nianie macierzy losowymi danymi
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			if (i == j) Matrix[i][j] = 0;
			else Matrix[i][j] = rand() % 100;
		}
	}
}

//Wypisanie macierzy
void Data::ShowMatrix()
{
	cout << endl;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			cout << Matrix[i][j];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//Dostep do ilo�ci miast
int Data::GetSize()
{
	return Size;
}

//Dost�p do wierzcho�ka pocz�tkowego
int Data::GetStartingPoint()
{
	return StartingPoint;
}

//Dost�p do kosztu
int Data::GetCost(int line, int column)
{
	return Matrix[line][column];
}

//Czyszczenie pami�ci
void Data::Clear()
{
	for (int i = 0; i < Size; i++)
	{
		delete[] Matrix[i];
	}
	delete[] Matrix;
}