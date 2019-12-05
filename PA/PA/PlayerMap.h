#pragma once
#include <string>
#include <iostream>
#include "Player.h"
#include "Console.h"
using namespace std;
class PlayerMap
{
public:
	int map[10][18];
	Player user;
	int x=0;
	int y=80;
	PlayerMap(string name);
	void drawmap(string filename);
	~PlayerMap();
	bool StrikeCheck();
	void movePlayer();
};

