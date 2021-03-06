#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
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
	void static Color(int color);
	void static showMatrix(int x, int y);
	void static setSizeDIAL();
	void static setSizeSetting();
};

