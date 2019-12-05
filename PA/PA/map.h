#pragma once
#include "Character.h"

class Map
	: public Character{
public:
	Map();
	int** map;
	int size_x, size_y;
	int speed;
	int stick_rate;
	int clear_line;

	int** genMap();
	void turn();
	void showMap();
};

