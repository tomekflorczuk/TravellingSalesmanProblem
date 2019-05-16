#pragma once
#include <iostream>
#include "Data.h"
#include "Menu.h"

using namespace std;

class DataMenu
{
	static int choice;
	static int size;
public:
	DataMenu();
	~DataMenu();
	void static ShowMenu();
};