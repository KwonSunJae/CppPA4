#pragma once
#include "Character.h"
#include <ctime>
class Map
	: public Character {
public:
	Map();
	int map[17][18];
	int size_x = 16, size_y = 16;
	int speed;
	int stick_rate;
	int clear_line;
	int time_now;
	int skill = 0;

	void genMap(int tmap[][18]);
	void fast(); //���� 2_1
	void line_up(); //���� 2_2
	void f_block(); //���� 3_1
	void invisible(); //���� 3_2
	void random_block(); //���� 4_1
	void turn(); //���� 4_2

	void delete_line(); // ���� 3_1 �����
};
