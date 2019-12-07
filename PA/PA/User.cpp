#include "User.h"

void User::setMem(bool* c)
{
	for (int i = 0; i < 8; i++) {
		isClear[i] = c[i];
	}
}

string User::getClearStr(const int& i)
{
	return isClear[i] ? "1" : "0";
}
