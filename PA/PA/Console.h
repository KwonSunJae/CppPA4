#pragma once
#include <Windows.h>
#include <conio.h>
using namespace std;
class Console
{
public:
	void gotoxy(int x, int y)

	{
		COORD pos = { x,y };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	}

	void SetColor(int color) {
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes & 0xf0) | (color & 0xf));
	}

	void clear() {
		system("cls");
	}
};

