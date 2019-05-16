#pragma once
#include <windows.h>
#include <iostream>
#include <iomanip>
#include "BF.h"
#include "BB.h"
#include "DP.h"
#include "DataMenu.h"

using namespace std;

class Menu
{
	static int choice;
	long long int static frequency, start, elapsed;
	Menu();
	~Menu();
public:
	long long int static read_QPC();
	void static ShowMenu();
};