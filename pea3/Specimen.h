#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Specimen
{
	int Cost;
	vector<int> Path;
public:
	Specimen(vector<int> path);
	Specimen();
	int GetCost();
	vector<int> GetPath();
	void SetPath(vector<int> path);
	static int CompareSpecimens(Specimen S1, Specimen S2);
};