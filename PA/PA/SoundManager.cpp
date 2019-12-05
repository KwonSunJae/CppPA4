#include "SoundManager.h"

void SoundManager::playListSND(const int& i)
{
	PlaySoundA(playList[i].c_str(), 0, SND_ASYNC | SND_ALIAS);
}

void SoundManager::playeffSND(const int& i)
{
	PlaySoundA(effectList[i].c_str(), 0, SND_ASYNC | SND_ALIAS);
}

void SoundManager::menuSND(const int& i)
{
	PlaySoundA(menuList[i].c_str(), 0, SND_ASYNC | SND_ALIAS);
}
