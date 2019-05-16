#pragma once
#include <vector>
#include "Specimen.h"

using namespace std;

class Data
{
	static int Size, StartingPoint, PopulationSize;
	static float MutationFactor, CrossoverFactor;
	static vector<vector<int>> Matrix;
	static vector<int> Vertexes;
public:
	Data();
	static void ReadFromFile();
	static void ShowData();
	static int GetCost(int i, int j);
	static int CalculateCost(vector<int> path);
	static vector<int> GetRandomPath();
	static int GetSize();
	static int GetStartingPoint();
	static int GetPopulationSize();
	static void SetPopulationSize(int populationsize);
	static float GetMutationFactor();
	static void SetMutationFactor(float mutationfactor);
	static float GetCrossoverFactor();
	static void SetCrossoverFactor(float crossoverfactor);
	static int GetVertexesSize();
	static void Clear();
};