#pragma once
#include "Data.h"
#include <vector>

class BF
{
	static int* visited;
	static int Size;
	static int it;
	static int startingpoint, currentpoint,  cost, mincost;
	static vector<int> points, minpoints;
public:
	BF();
	~BF();
	int static GetStartingPoint();
	int static GetCurrentPoint();
	void static BruteForce(int currentpoint);
	void static ShowResult();
	void static Clear();
};