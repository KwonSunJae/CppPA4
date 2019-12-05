#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
class Console
{
	void clear();
	void goxy(int x, int y);
	int getKey_Input(); //키보드 입력
	void draw_file(int x, int y, string file);
	void Color(int color);
};

