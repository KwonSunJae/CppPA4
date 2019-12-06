#include "Console.h"

void Console::clear()
{
	system("cls");
}

void Console::goxy(int x, int y)
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Console::Color(int color)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes & 0xf0) | (color & 0xf));
}

void Console::showMatrix(int x, int y)
{
	Console::setFontSize(8, 12);
	Console::setConsoleSize(200, 100);
}

void Console::setFontSize(const int& x, const int& y)
{
	CONSOLE_FONT_INFOEX cfi;

	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = x;                   // Width of each character in the font
	cfi.dwFontSize.Y = y;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Console::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Console::setConsoleSize(const int& x, const int& y)
{
	char command[COMMAND_SIZE] = { '\0', };
	int lines = y;
	int cols = x;
	sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
	system(command);
}

void Console::setSizeStory()
{
	/*Console::setFontSize(1, 2);
	Console::setConsoleSize(500, 200);*/
	Console::setFontSize(2, 4);
	Console::setConsoleSize(501, 190);

}

void Console::setSizeGame()
{
	Console::setFontSize(2, 4);
	Console::setConsoleSize(750, 256);
}

void Console::setSizeMSel()
{
	Console::setFontSize(2, 4);
	Console::setConsoleSize(501, 128);

}

void Console::setTetrisGame()
{
	Console::setFontSize(5, 10);
	Console::setConsoleSize(80, 50);
}
