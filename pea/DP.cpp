#include "DP.h"

int DP::Size;
int DP::visited;
int DP::cost;
int DP::mincost;
int DP::Subset;
int** DP::Matrix;

//Konstruktor
DP::DP()
{
	Size = Data::GetSize();
	Subset = pow(2, Size);
	//Generowanie macierzy pomocnicznej
	Matrix = new int *[Subset];
	for (int i = 0; i < Subset; i++)
		Matrix[i] = new int[Size];
	//Zerowanie macierzy pomocniczej
	for (int i = 0; i < Subset; i++)
		for (int j = 0; j < Size; j++)
			Matrix[i][j] = 0;
	visited = (1 << Size) - 1;
	cost = 0;
	mincost = INT_MAX;
}

//Destruktor
DP::~DP()
{
}

//Programowanie dynamiczne
void DP::DynamicProgramming(int mask, int currentpoint, int &currentcost)
{	
	mincost = INT_MAX;
	if (mask != visited)
	{
		if (Matrix[mask][currentpoint] == 0)
		{
			for (int i = 0; i < Size; i++)
			{
				if ((mask&1 << i) == 0)
				{
					int cost = Data::GetCost(currentpoint, i);
					DynamicProgramming(mask | 1 << i, i, cost);
					if (cost < mincost) mincost = cost;
				}
			}
			Matrix[mask][currentpoint] = mincost;
			currentcost = currentcost + Matrix[mask][currentpoint];
		}	
		currentcost = currentcost + Matrix[mask][currentpoint];
	}
	currentcost = currentcost + Data::GetCost(currentpoint, Data::GetStartingPoint());
}

int DP::GetCost()
{
	return cost;
}

void DP::ShowMatrix()
{
	for (int i = 0; i < Subset; i++)
	{
		for (int j = 0; j < Size; j++)
			cout << setw(3) << Matrix[i][j];
		cout << endl;
	}
}

//Wyœwietlenie wyniku
void DP::ShowResult()
{
	cout << "$" << mincost << endl;
}

//Czyszczenie pamiêci
void DP::Clear()
{
	for (int i = 0; i < Subset; i++)
	{
		delete[] Matrix[i];
	}
	delete[] Matrix;
}