#pragma once
#include "Data.h"
#include <iomanip>

class DP
{
	int static Size, visited, cost, mincost, Subset;
	static int** Matrix;
public:
	DP();
	~DP();
	void static DynamicProgramming(int mask, int currentpoint, int &currentcost);
	int static GetCost();
	void static ShowMatrix();
	void static ShowResult();
	void static Clear();
};