#pragma once
#include "Character.h"
#include <ctime>
class Map
	: public Character {
public:
	Map();
	int** map;
	int size_x, size_y;
	int speed;
	int stick_rate;
	int clear_line;
	int time_now;
	int skill = 0;

	int** genMap();
	void fast(); //레벨 2_1
	void line_up(); //레벨 2_2
	void f_block(); //레벨 3_1
	void invisible(); //레벨 3_2
	void random_block(); //레벨 4_1
	void turn(); //레벨 4_2

};

