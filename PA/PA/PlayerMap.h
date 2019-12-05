#pragma once
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;
class PlayerMap
{
public:
	string fileName;
	Player user;
	PlayerMap(string name);

	~PlayerMap();

};

