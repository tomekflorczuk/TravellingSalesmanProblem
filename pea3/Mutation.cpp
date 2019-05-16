#include "Mutation.h"
#include "MutationMenu.h"
#include <time.h>
#include <iostream>

vector<int> Mutation::Mutate(vector<int> vertexes)
{
	vector<int> mutatedvertexes = vertexes;
	int i, j;

	switch(MutationMenu::GetMutationChoice())
	{
	//Mutacja typu inverison
	case(1):
		{
		i = rand() % vertexes.size();
		do
		{
			j = rand() % vertexes.size(); 
		} while (i == j);

		if (i > j)
			swap(i, j);

		for (; i < j; i++, j--)
		{
			mutatedvertexes[i] = vertexes[j];
			mutatedvertexes[j] = vertexes[i];
		}
		return mutatedvertexes;
		}
	//Mutacja typu insertion
	case(2):
		{
		i = rand() % vertexes.size();
		do
		{
			j = rand() % vertexes.size();
		} while (i == j);

		mutatedvertexes.erase(mutatedvertexes.begin() + j);
		mutatedvertexes.insert(mutatedvertexes.begin() + i, vertexes[j]);
		return mutatedvertexes;
		}
	//Mutacja typu displacement
	case(3):
		{

		i = rand() % vertexes.size();
		do
		{
			j = rand() % vertexes.size();
		} while (i == j);

		swap(mutatedvertexes[i], mutatedvertexes[j]);
		return mutatedvertexes;
		}
	//Mutacja typu transposition
	case(4):
		{
		i = rand() % vertexes.size();
		do
		{
			j = rand() % vertexes.size();
		} while (i == j);

		swap(mutatedvertexes[i], mutatedvertexes[j]);
		return mutatedvertexes;
		}
	default: cout << "Cos poszlo nie tak." << endl;
	}
}