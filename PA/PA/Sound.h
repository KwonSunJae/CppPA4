#pragma once
#include <string>
using namespace std;
class Sound
{
	enum {
		LEVEL_1,
		LEVEL_2,
		LEVEL_3,
		LEVEL_4,
		LEVEL_5
	};	/// bgmList
	enum {
		STACKING_BLOCK,
		ERASE_BLOCK,
		CLEAR_SND,
		OVER_SND,
		SKILL_SND,
		MOVE_SND,
		DIALOUGE_SND
	};	/// gameSNDList
	enum {
		MENU_MOVE,
		MENU_SEL
	};	/// menuSNDList


	const string bFileName = "bgmList.txt";
	const string gameSNDList = "gameSNDList.txt";
	const string menuSNDList = "menuSNDList.txt";

	string bgmList[5];
	string gameSNDList[7];
	string menuSNDList[2];
public:
	Sound();
	void bgmPlay(const int& i);
	void gSNDPlay(const int& i);
	void mSNDPlay(const int& i);
};
/// 사운드 실행
