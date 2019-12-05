#include "Menu.h"
#include "Console.h"
using namespace std;

void Menu::printTxt(const string& filename)
{
	ifstream fin(filename);
	if (fin.is_open()) {
		int num; fin >> num;
		string tmp;
		for (int i = 0; i < num; i++) {
			getline(fin, tmp);
			cout << tmp << endl;
		}
	}
}

void Menu::printPressStart()
{
	Console::setSizeStory();
	while (true) {
		if (_kbhit())
			break;
		Console::gotoxy(0, 0);
		printTxt("pressStart.txt");
		Sleep(500);
		if (_kbhit())
			break;
		Console::gotoxy(0, 135);
		printTxt("blank.txt");
		Sleep(500);
		if (_kbhit())
			break;
	}
	system("cls");
}

int Menu::menuSel()
{
	cin.clear();
	cin.ignore();
	Console::setSizeMSel();
	printTxt("menu1.txt");
	string menuList[4] = { "menu1.txt","menu2.txt","menu3.txt","menu4.txt" };
	int curr = 0;
	int limit_min = 0;
	int limit_max = 3;
	while (true) {
		int ch;
		if (_kbhit()) {
			ch = getch();
			if (ch == 224) {
				ch = getch();
				switch (ch) {
				case 72: {
					if (curr != limit_min) {
						curr--;
						Beep(700, 350);
						Console::gotoxy(0, 0);
						printTxt("menu.txt");
						Console::gotoxy(0, 0);
						printTxt(menuList[curr].c_str());
					}
					break;
				}
				case 80:
					if (curr != limit_max) {
						curr++;
						Beep(700, 350);
						Console::gotoxy(0, 0);
						printTxt("menu.txt");
						Console::gotoxy(0, 0);
						printTxt(menuList[curr].c_str());
					}
				}
			}
			if (ch == 13) {
				Beep(500, 450);
				return curr;
			}
		}
	};
}


