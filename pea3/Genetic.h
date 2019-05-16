#pragma once
#include <iostream>
#include <vector>
#include "Specimen.h"

using namespace std;

class Genetic
{
	static Specimen BestSolution;
public:
	static void Algorithm();
	inline static float Random();
	static void ShowResult();
};