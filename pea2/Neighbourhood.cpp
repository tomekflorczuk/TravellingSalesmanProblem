#include "Neighbourhood.h"

//Znalezienie s¹siada
vector<int> Neighbourhood::FindNeighbour(vector<int> vertexes, int i, int j)
{
	srand(time(nullptr));
	vector<int> neighbourhoodvertexes = vertexes;
	
	switch(NeighbourhoodMenu::GetNeighbourhoodChoice())
	{
	//Znalezienie s¹siada typu insert
	case(1):
		{
			neighbourhoodvertexes.erase(neighbourhoodvertexes.begin() + j);
			neighbourhoodvertexes.insert(neighbourhoodvertexes.begin() + i, vertexes[j]);
			return neighbourhoodvertexes;
		}
	//Znalezenie s¹saida typu swap
	case(2):
		{		
			neighbourhoodvertexes[i] = vertexes[j];
			neighbourhoodvertexes[j] = vertexes[i];
			return neighbourhoodvertexes;
		}
	//Znalezienie s¹siada typu invert
	case(3):
		{
			if(i > j)
				swap(i, j);
			for(;i < j; i++, j--)
			{
			neighbourhoodvertexes[i] = vertexes[j];
			neighbourhoodvertexes[j] = vertexes[i];
			}
			return neighbourhoodvertexes;
		}
	default: cout << "Cos poszlo nie tak" << endl;
	}
	return neighbourhoodvertexes;
}