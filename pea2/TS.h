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
	void static ToogleDiversification();
	bool static GetDiversification();
	void static Algorithm();
	inline bool static Aspiration(int neighbourcost);
	inline bool static CriticalEvent(int iterations);
	vector<int> static Restart();
	void static ShowResult();
};