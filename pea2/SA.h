#pragma once
#include <algorithm>
#include "Data.h"
#include "Neighbourhood.h"
#include "Clock.h"
#include <math.h>
#include <fstream>

class SA
{
	static int mincost;
	static vector<int> minvertexes;
	static const int maxit;
public:
	void static Algorithm();
	inline float static Probability(int cost, int neighbourcost, float t);
	inline float static Random();
	void static ShowResult();
};