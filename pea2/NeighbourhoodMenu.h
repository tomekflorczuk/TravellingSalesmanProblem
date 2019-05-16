#pragma once
#include <iostream>

class NeighbourhoodMenu
{
	static int neighbourhoodchoice;
public:
	NeighbourhoodMenu();
	int static GetNeighbourhoodChoice();
	void static ShowMenu();
};