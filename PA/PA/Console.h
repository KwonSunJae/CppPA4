#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

#define COMMAND_SIZE 256
using namespace std;
class Console
{
public:
	void clear();
	void goxy(int x, int y);
	void static setFontSize(const int& x, const int& y);
	void static gotoxy(int x, int y);
	void static setConsoleSize(const int& x, const int& y);
	void static setSizeStory();
	void static setSizeGame();
	void static setSizeMSel();
	void static setTetrisGame();
	void Color(int color);
};

