#include "UserManager.h"
#include "Console.h"
#include <iostream>
#include <sstream>
#include <conio.h>
using namespace std;
UserManager::UserManager()
{
	ifstream fin(FILENAME);
	if (fin.is_open()) {
		string tmp_name;
		while (fin >> tmp_name) {
			string bstr;
			fin >> bstr;
			bool isB;
			if (bstr.at(0) == '0')
				isB = false;
			else
				isB = true;
			bool isC[8];
			for (int i = 0; i < 8; i++) {
				if (bstr.at(2 + i) == '0')
					isC[i] = false;
				else
					isC[i] = true;
			}
			userIDList.push_back(userList.size());
			User* tU = new User(tmp_name, isB);
			tU->setMem(isC);
			userList.push_back(tU);
		}
	}
	fin.close();
}

bool UserManager::checkOL(const string& n)
{
	bool flag = true;
	for (int i = 0; i < userList.size(); i++) {
		flag &= (n != userList[i]->getName());
	}
	return flag;
}

User* UserManager::getUser(const int& i)
{
	return userList[i];
}

User* UserManager::getCurrUser()
{
	return currUser;
}

void UserManager::newCurrUser(const string& n)
{
	User* newCurr = new User(n, false);
	currUser = newCurr;
}

void UserManager::loadUser(const string& n)
{
	/// 저장해줌 근데 이미 저장한건지 안한건지 확인해야함
	if (isLoad(n)) {
		userIDList.push_back(userList.size());
		userList.push_back(currUser);
		vector<string> tmp;
		ifstream fin(FILENAME);
		if (fin.is_open()) {
			string tstr;
			while (fin >> tstr) {
				fin >> tstr;
				tmp.push_back(tstr);
				fin >> tstr;
				tmp.push_back(tstr);
			}
		}
		for (int i = 0; i < tmp.size() / 2; i++) {
			if (tmp[i * 2] == n) {
				string bstr = "";
				if (currUser->hasBonus())
					bstr += "1";
				else
					bstr += "0";
				bstr += "9";
				for (int i = 0; i < 8; i++) {
					bstr += currUser->getClearStr(i);
				}
				tmp[(2 * i) + 1] = bstr;
			}
		}
		fin.close();
		ofstream ofin;
		ofin.open(FILENAME);
		if (ofin.is_open()) {
			for (int i = 0; i < tmp.size(); i++) {
				ofin << tmp[2 * i] << endl;
				ofin << tmp[(2 * i) + 1] << endl;
			}
		}
		ofin.close();
	}
	else {
		userIDList.push_back(userList.size());
		userList.push_back(currUser);
		ofstream ofin;
		ofin.open(FILENAME, ios::app);
		if (ofin.is_open()) {
			ofin << currUser->getName() << endl;
			string tmpBstr = "";
			if (currUser->hasBonus())
				tmpBstr += "1";
			else
				tmpBstr += "0";
			tmpBstr += "9";
			for (int i = 0; i < 8; i++) {
				tmpBstr += currUser->getClearStr(i);
			}
			ofin << tmpBstr << endl;
		}
	}
}


void UserManager::delUser()
{
	/// 저장 안하고 게임 종료 하면 현재 currUser 삭제

	delete currUser;
	currUser = nullptr;

}

bool UserManager::eraseData(const string& n)
{
	bool flag = false;
	vector<string> onLoad;
	ifstream fin(FILENAME);
	if (fin.is_open()) {
		string tmp;
		while (fin >> tmp) onLoad.push_back(tmp);
	}
	fin.close();
	for (int i = 0; i < onLoad.size() / 2; i++) {
		if (onLoad[2 * i] == n) {
			onLoad[2 * i] = "";
			onLoad[(2 * i) + 1] = "";
			flag = true;
			break;
		}
	}
	ofstream ofin(FILENAME);
	if (ofin.is_open()) {
		for (int i = 0; i < onLoad.size(); i++) {
			if (onLoad[i] != "")
				ofin << onLoad[i] << endl;
		}
	}
	return flag;
}

bool UserManager::isLoad(const string& n)
{
	ifstream fin(FILENAME);
	if (fin.is_open()) {
		string cname;
		string tstr;
		while (fin >> cname) {
			if (cname == n) {
				fin.close();
				return true;
			}
			fin >> tstr;
		}
		fin.close();
		return false;
	}
}

int UserManager::SetOnLoad()
{
	Console::setSizeSetting();
	Console::gotoxy(10, 5);
	string friendlist[8] = { "오로나민C","Dr.스톤핸즈","나댄서","강재수","???","술잘먹","전자석","만쥬" };
	cout << "=======================SAVE LIST========================";
	for (int i = 0; i < userList.size(); i++) {
		Console::gotoxy(10, 7 + i * 2);
		cout << "[" << i + 1 << "] " << userList[i]->getName() << " / 친구목록 : ";
		for (int k = 0; k < 8; k++) {
			if (userList[i]->getClearStr(k) == "1")
				cout << friendlist[k] << " ";
		}
	}
	int res = 0;
	int limit = userList.size() - 1;
	Console::gotoxy(10, 8);
	cout << ">------------------------------------------<";
	while (true) {
		int ch;
		if (_kbhit()) {
			ch = _getch();
			if (ch == 13)
				return res;
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

string UserManager::enterName()
{
	Console::setSizeSetting();
	Console::setSizeSetting();
	Console::gotoxy(10, 3);
	cout << "===============PLZ TAP THE ENTER TWICE===================";
	while (true) {
		Console::gotoxy(10, 7);
		cout << "                                                                                               ";
		Console::gotoxy(10, 5);
		cout << "                                                                                    ";
		Console::gotoxy(10, 5);
		cout << "ENTER : ";
		string tmp_name;
		cin >> tmp_name;
		if (!this->checkOL(tmp_name)) {
			Console::gotoxy(10, 7);
			cout << "중복 이름!!! 다시 입력해주세요 ";
			system("pause");
			continue;
		}
		else
			return  tmp_name;
	}
}

//User& UserManager::newUser()
//{
//	return null;// TODO: 여기에 반환 구문을 삽입합니다.
//}
