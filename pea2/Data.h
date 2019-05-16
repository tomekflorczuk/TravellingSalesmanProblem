	#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <windows.h>

using namespace std;

class Data
{
	static int  Size, StartingPoint;
	static float MaxCost;
	static int** Matrix;
	static vector<int> Vertexes;
public:
	Data();
	void static ReadFromFile();
	void static Generate(int size);
	int static GetSize();
	int static GetStartingPoint();
	float static GetMaxCost();
	int static GetCost(int i, int j);
	int static CalculateCost(vector<int> vertexes);
	vector<int> static &GetVertexes();
	vector<int> static RandomVertexes();
	void static ShowMatrix();
	void static ShowVertexes();
	void static Clear();
};