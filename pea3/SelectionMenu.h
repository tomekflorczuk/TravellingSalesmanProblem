#pragma once

class SelectionMenu
{
	static int selectionchoice;
public:
	SelectionMenu();
	static void ShowMenu();
	static int GetSelectionChoice();
};