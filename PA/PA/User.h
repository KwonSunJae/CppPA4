#pragma once
#include <string>
using namespace std;
class User
{
	string name;
	bool isClear[8] = { 0, };
	bool isBonus;
public:
	User(const string& name, const bool b) :name(name), isBonus(b) {}
	string getName() { return name; }
	void setMem(bool* c);
	int hasBonus() { return isBonus; }
	string getClearStr(const int& i);
};
