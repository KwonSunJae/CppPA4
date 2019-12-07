#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <string>
#pragma comment(lib, "winmm.lib")

using namespace std;

class SoundManager
{
	string playList[3] = { "play1.wav","play2.wav" ,"play3.wav" };
	string effectList[7] = { "BLOCK_DAT.wav","ERASE.wav","CLEAR.wav","FAIL.wav","SKILL.wav","MOVE.wav","DIALOG.wav" };
	string menuList[3] = { "menuBGM1.wav","menuBGM2.wav","menuBGM3.wav" };
	int currPlay = 0;
public:
	enum {
		DAT,
		ERASE,
		CLEAR,
		FAIL,
		SKILL,
		MOVE,
		DIALOG
	};
	enum {
		PLAY1,
		PLAY2,
		PLAY3,
		PLAY4,
		PLAY5
	};
	enum {
		BGM1,
		BGM2,
		BGM3
	};
	void playListSND(const int& i);
	void playeffSND(const int& i);
	void menuSND();
	void setSoundID();
};
