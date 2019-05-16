#include "Crossover.h"

//Krzy¿owanie OX
vector<int> Crossover::Cross(vector<int> parent1, vector<int> parent2)
{
	vector<int> child;
	vector<int> visited;
	int i, j, size = parent1.size();

	child.resize(size);
	visited.resize(size);
	//Losowanie punktów przeciêæ
	i = rand() % size;
	do
	{
		j = rand() % size;
	} while (i == j);

	if (i > j)
		swap(i, j);

	//Przepisanie segmentu z rodzica 1 do dziecka
	for(int k = i; k < j; k++)
	{
		child[k] = parent1[k];
		visited[parent1[k] - 1] = 1;
	}
	//Uzupe³enienie dziecka pozosta³ymi wierzcho³kami z rodzica 2
	for(int k = j; k != i; k++)
	{
		if(k == size)
		{
			k = -1;
			continue;	
		}
		//Sprawdzenie czy wierzcho³ek znajduje siê ju¿ w dziecku
		while (visited[parent2[j] - 1] == 1)
		{
			j++;
			if (j == size)
				j = 0;
		}
		
		child[k] = parent2[j];
		j++;

		if(j == size)
			j = 0;
	}
	return child;
}