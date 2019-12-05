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
	int x;
	int y;
	string draw[8][15];
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
	void Print(int i, int x, int y);
	int exMove[2] = { RS,0 };
	void PrintPlayer(int i);
	Player(string name);
	void MovePlayer(int i, int x, int y);
	void MovePlayer();
	~Player();
};

