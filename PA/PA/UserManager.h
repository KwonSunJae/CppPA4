#pragma once
#include "User.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class UserManager
{
	vector<User*> userList;
	vector<int> userIDList;
	User* currUser = nullptr;
	const string FILENAME = "userList.txt";
public:
	UserManager();
	bool checkOL(const string& n); /// 중복 되는거 있으면 false
	User* getUser(const int& i);
	User* getCurrUser();
	void newCurrUser(const string& n);
	void loadUser(const string& n);
	void delUser();
	bool eraseData(const string& n);
	bool isLoad(const string& n);
	int SetOnLoad();
	string enterName();
};

