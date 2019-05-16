#pragma once
#include "Data.h"
#include "Neighbourhood.h"
#include "Clock.h"
#include <fstream>
#include <iomanip>

class TS
{
	static int mincost;
	static vector<int> minvertexes;
	static bool Diversification;
public:
	TS();
	void static ToogleDiversification();
	bool static GetDiversification();
	void static Algorithm();
	bool static Aspiration(int neighbourcost);
	bool static CriticalEvent(int iterations);
	vector<int> static Restart();
	void static ShowResult();
};