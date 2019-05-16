#include "BF.h"

int* BF::visited;
int BF::Size;
int BF::it;
int BF::startingpoint;
int BF::currentpoint;
int BF::cost;
int BF::mincost;
vector<int> BF::points;
vector<int> BF::minpoints;

//Konstruktor
BF::BF()
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

//Desktrutor
BF::~BF()
{	
}

//Dostêp do wierzcho³ka pocz¹tkowego
int BF::GetStartingPoint()
{
	return startingpoint;
}

//Dostêp do wierzcho³ka obecnego
int BF::GetCurrentPoint()
{
	return currentpoint;
}

//Przegl¹d zupe³ny
void BF::BruteForce(int currentpoint)
{
	if (it != Size - 1)
	{
		visited[currentpoint] = 1;
		for (int i = 1; i < Size; i++)
		{
			if (visited[i] == 1) continue;
			cost = cost + Data::GetCost(currentpoint, i);
			points[it] = i;
			it++;
			BruteForce(i);
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

//Wyœwietlenie wyniku
void BF::ShowResult()
{
	/*cout << minpoints2.back();
	minpoints2.pop_back();
	while (! minpoints2.empty())
	{
		cout << "->" << minpoints2.back();
		minpoints2.pop_back();
	}*/
	cout << "0->";
	for(int i = 0; i < Size - 1; i++)
	{
		cout << minpoints[i] << "->";
	}
	cout << "0";
	cout << endl;
	cout << "$" << mincost << endl;
}

//Zwalnianie pamieci
void BF::Clear()
{
	delete[] visited;
	while (!points.empty()) points.pop_back();
	while (!minpoints.empty()) minpoints.pop_back();
	//while (!points2.empty()) points2.pop_front();
	//while (!minpoints2.empty()) minpoints2.pop_front();
}