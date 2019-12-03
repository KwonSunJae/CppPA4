#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
class Map
{
public:


public:
	Map();
	~Map();
	void gotoxy(int x, int y); //커서옮기기
	void SetColor(int color); //색표현
};

