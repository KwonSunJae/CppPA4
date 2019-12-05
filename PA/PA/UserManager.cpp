#include "UserManager.h"
#include <iostream>
#include <sstream>
using namespace std;
UserManager::UserManager()
{
	ifstream fin(FILENAME);
	if (fin.is_open()) {
		string tmp_name;
		while (!fin.eof()) {
			bool check[10];
			bool isB;
			fin >> tmp_name;
			if (tmp_name == "STOP0010203495412")
				break;
			string tstr;
			getline(fin, tstr);
			getline(fin, tstr);
			stringstream sst(tstr);
			string token;
			int tmp_index = 0;
			while (sst >> token) {
				if (tmp_index == 0) {
					isB = token == "true" ? true : false;
					tmp_index++;
				}
				else
					check[tmp_index++] = (token == "true" ? true : false);
			}
			User* tU = new User(tmp_name, isB);
			tU->setMem(check);
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
		userList.push_back(currUser);
		vector<string> tmp;
		ifstream fin(FILENAME);
		if (fin.is_open()) {
			string tstr;
			while (fin) {
				fin >> tstr;
				tmp.push_back(tstr);
				fin >> tstr;
				tmp.push_back(tstr);
				getline(fin, tstr);
				tmp.push_back(tstr);
			}
		}
		for (int i = 0; i < tmp.size() / 3; i++) {
			if (tmp[i * 3] == n) {
				tmp[i * 3 + 1] = currUser->hasBonus();
				string boolstr;
				for (int i = 0; i < 10; i++) {
					if (i == 9)
						boolstr += currUser->getClearStr(i);
					boolstr += currUser->getClearStr(i);
					boolstr += " ";
				}
			}
		}
		fin.close();
		ofstream ofin;
		ofin.open(FILENAME, ios::out);
		if (ofin.is_open()) {
			for (int i = 0; i < tmp.size(); i++) {
				if (i % 3 == 1) {
					tmp[i] += " ";
					string tss;
					tss += tmp[i];
					tss += tmp[i + 1];
					tmp[i + 1] = tss;
					continue;
				}
				else
					ofin << tmp[i] << endl;
			}
		}
		ofin.close();
	}
	else {
		userList.push_back(currUser);
		ofstream ofin;
		ofin.open(FILENAME, ios::app);
		if (ofin.is_open()) {
			ofin << currUser->getName() << endl;
			if (currUser->hasBonus())
				ofin << "true" << " ";
			else
				ofin << "false" << " ";
			for (int i = 0; i < 10; i++) {
				if (i == 9)
					ofin << currUser->getClearStr(i) << endl;
				else
					ofin << currUser->getClearStr(i) << " ";
			}
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
	/// txt파일에서 네임 찾아서 지워줌
	vector<User*>::iterator it = userList.begin();
	for (int i = 0; i < userList.size(); i++) {
		if (userList[i]->getName() == n) {
			userList.erase(it);
			break;
		}
		it++;
	}
	if (isLoad(n)) {
		vector<string> tmp;
		ifstream fin(FILENAME);
		if (fin.is_open()) {
			string tstr;
			while (fin >> tstr) {
				tmp.push_back(tstr);
				fin >> tstr;
				tmp.push_back(tstr);
				getline(fin, tstr);
				tmp.push_back(tstr);
			}
		}
		int id;
		for (int i = 0; i < tmp.size() / 3; i++) {
			if (tmp[i * 3] == n) {
				id = i * 3;
			}
		}
		fin.close();
		ofstream ofin;
		ofin.open(FILENAME, ios::out);
		if (ofin.is_open()) {
			for (int i = 0; i < tmp.size();) {
				if (i == id) {
					i += 3;
				}
				else {
					if (i % 3 == 1) {
						tmp[i] += " ";
						string tss = "";
						tss += tmp[i];
						tss += tmp[i + 1];
						tmp[i + 1] = tss;
						i++;
					}
					else
						ofin << tmp[i++] << endl;
				}
			}
		}
		ofin.close();
		return true;
	}
	else
		return false;

}

bool UserManager::isLoad(const string& n)
{
	ifstream fin(FILENAME);
	if (fin.is_open()) {
		string cname;
		string tstr;
		while (fin) {
			fin >> cname;
			if (cname == n) {
				fin.close();
				return true;
			}
			fin >> cname;
			getline(fin, tstr);
		}
		fin.close();
		return false;
	}
	else {
		cout << "파일 오류" << endl;
		return false;
	}
}

//User& UserManager::newUser()
//{
//	return null;// TODO: 여기에 반환 구문을 삽입합니다.
//}
