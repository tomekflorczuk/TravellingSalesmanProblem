#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Data
{
	static int Size, StartingPoint;
	static int** Matrix;
public:
	Data();
	~Data();
	void static ReadFromFile();
	void static Generate(int size);
	void static ShowMatrix();
	int static GetSize();
	int static GetStartingPoint();
	int static GetCost(int row, int line);
	void static Clear();
};