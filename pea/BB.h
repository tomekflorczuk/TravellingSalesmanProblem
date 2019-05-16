#pragma once
#include "Data.h"
#include <vector>

class BB
{
	static int* visited;
	int static Size;
	static int it;
	static int startingpoint, currentpoint, cost, mincost;
	static vector<int> points, minpoints;
public:
	BB();
	~BB();
	int static GetStartingPoint();
	void static BranchAndBound(int currentpoint);
	int static Boundary(int currentpoint);
	void static ShowResult();
	void static Clear();
};
