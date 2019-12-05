#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include<Windows.h>
#include <fstream>
using namespace std;
class Player
{
public:
	enum move {
		RS,
		R1,
		R2,
		RJ,
		LS,
		L1,
		L2,
		LJ
	};
	string IMGfile[8] ;
	string pname;
	int exMove[2] = { RS,0 };
	void PrintPlayer(int i);
	Player(string name);
	void MovePlayer();
	~Player();
};

