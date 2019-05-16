#include "BB.h"

int* BB::visited;
int BB::Size;
int BB::it;
int BB::startingpoint;
int BB::currentpoint;
int BB::cost;
int BB::mincost;
vector<int> BB::points;
vector<int> BB::minpoints;

//Konstruktor
BB::BB()
{
	Size = Data::GetSize();
	visited = new int[Size];
	for (int i = 0; i < Size; ++i)
		visited[i] = 0;
	startingpoint = 0;
	cost = 0;
	it = 0;
	currentpoint = startingpoint;
	mincost = INT_MAX;
	for (int i = 1; i < Size; i++)
		points.push_back(i);
}

//Destruktor
BB::~BB()
{
}

//Dostêp do wierzcho³ka startowego
int BB::GetStartingPoint()
{
	return startingpoint;
}

//Metoda podzia³u i ograniczeñ
void BB::BranchAndBound(int currentpoint)
{
	if (it != Size - 1)
	{
		visited[currentpoint] = 1;
		for (int i = 1; i < Size; i++)
		{
			if (visited[i] == 1) continue;
			if (Boundary(i) > mincost) continue;;
			cost = cost + Data::GetCost(currentpoint, i);
			points[it] = i;
			it++;
			BranchAndBound(i);
			cost = cost - Data::GetCost(currentpoint, i);
		}
	}
	else
	{
		cost = cost + Data::GetCost(currentpoint, startingpoint);
		if (cost < mincost)
		{
			mincost = cost;
			minpoints = points;
		}
		cost = cost - Data::GetCost(currentpoint, startingpoint);
	}
	visited[currentpoint] = 0;
	it--;
}

//Obliczanie granicy
int BB::Boundary(int currentpoint)
{	
	int mincost;
	int bound = 0;
	int result = cost;

	for (int i = 0; i < Size; i++)
	{
		if (visited[i] == true) continue;
		mincost = INT_MAX;
		
		for(int j = 1; j < Size; j++)//Koszty wyjœcia z wierzcho³ka
		{
			if(visited[j] == 1 || i == j) continue;
			if (Data::GetCost(i, j) < mincost) mincost = Data::GetCost(i, j);
		}
		if (Data::GetCost(i, startingpoint) < mincost) mincost = Data::GetCost(i, startingpoint);
		bound = bound + mincost;
		
		mincost = INT_MAX;
		for (int j = 0; j < Size; j++)//Koszty wejœcia do wierzcho³ka
		{
			if (visited[j] == 1 || i == j) continue;
			if (Data::GetCost(j, i) < mincost) mincost = Data::GetCost(j, i);
		}
		if (Data::GetCost(currentpoint, i) < mincost) mincost = Data::GetCost(currentpoint, i);
		bound = bound + mincost;
	}

	return result + bound / 2;
}

//Wyœwietlenie wyniku
void BB::ShowResult()
{
	cout << "0->";
	for (int i = 0; i < Size - 1; i++)
	{
		cout << minpoints[i] << "->";
	}
	cout << "0";
	cout << endl;
	cout << "$" << mincost << endl;
}

//Zwalnianie pamiêci
void BB::Clear()
{
	delete[] visited;
	while (!points.empty()) 
		points.pop_back();
	while (!minpoints.empty()) 
		minpoints.pop_back();
}