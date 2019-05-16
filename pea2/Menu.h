#pragma once
#include "Data.h"
#include "SA.h"
#include "TS.h"
#include "Neighbourhood.h"
#include "NeighbourhoodMenu.h"
#include "Clock.h"
#include <iostream>

class Menu
{
	static int choice;
	Menu();
public:
	void static ShowMenu();
};