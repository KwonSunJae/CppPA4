#include "SoundManager.h"
#include "Console.h"
void SoundManager::playListSND(const int& i)
{
	PlaySound(playList[i].c_str(), 0, SND_ASYNC | SND_ALIAS);
}

void SoundManager::playeffSND(const int& i)
{
	PlaySound(effectList[i].c_str(), 0, SND_ASYNC | SND_ALIAS);
}

void SoundManager::menuSND()
{
	switch (currPlay) {
	case 0:
		PlaySound("play1.wav", 0, SND_ASYNC | SND_LOOP);
		return;
	case 1:

		PlaySound("play2.wav", 0, SND_ASYNC | SND_LOOP);
		return;
	case 2:

		PlaySound("play3.wav", 0, SND_ASYNC | SND_LOOP);
		return;

	}
}


void SoundManager::setSoundID()
{
	Console::setSizeSetting();
	Console::gotoxy(10, 3);
	cout << "===============PLZ TAP THE ENTER TWICE===================";
	Console::gotoxy(10, 5);
	cout << "=======================SOUND LIST========================";
	for (int i = 0; i < 3; i++) {
		Console::gotoxy(10, 7 + i * 2);
		cout << "[" << i + 1 << "] " << playList[i];
	}
	int res = 0;
	int limit = 2;
	Console::gotoxy(10, 8);
	cout << ">------------------------------------------<";
	while (true) {
		int ch;
		if (_kbhit()) {
			ch = _getch();
			if (ch == 13) {
				currPlay = res;
				break;
			}
			if (ch == 224) {
				ch = _getch();
				if (ch == 80) {
					if (res != limit) {
						Console::gotoxy(10, 8 + 2 * res);
						cout << "                                             ";
						res++;
						Console::gotoxy(10, 8 + 2 * res);
						cout << ">------------------------------------------<";
					}
				}
				if (ch == 72) {
					if (res != 0) {
						Console::gotoxy(10, 8 + 2 * res);
						cout << "                                             ";
						res--;
						Console::gotoxy(10, 8 + 2 * res);
						cout << ">------------------------------------------<";
					}
				}

			}
		}
	}
}