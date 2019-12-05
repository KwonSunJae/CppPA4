#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

class Menu
{
public:
	void printTxt(const string& filename);
	void printPressStart();
	int menuSel();
};

