#include "User.h"

void User::setMem(bool* c)
{
	for (int i = 0; i < 10; i++) {
		isClear[i] = c[i];
	}
}

string User::getClearStr(const int& i)
{
	return isClear[i] ? "true" : "false";
}
