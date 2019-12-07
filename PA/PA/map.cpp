#include "Map.h"
#include <iostream>
#include <algorithm>
using namespace std;

Map::Map() {
}

void Map::genMap(int tmap[][18]) {
	for (int i = 0; i < size_y + 1; i++) {
		memset(tmap[i], 0, sizeof(int) * 18);
		for (int j = 0; j < size_x + 2; j++) {
			if (i == size_y || j == 0 || j == size_x + 1) {
				tmap[i][j] = 2;
			}
			
		}
		
	}

}

void Map::fast() // 1
{
	if (!skill) {
		speed = 4;
		time_now = time(NULL);
	}
	else {
		skill = 0;
	}
}

void Map::line_up() // 2
{
	for (int i = 1; i <= size_x; i++) {
		int j;
		for (j = 0; j < size_y; j++) {
			map[j][i] = map[j + 1][i];
		}
		map[size_y][i] = 1;
	}
	for (int i = 0; i < 3; i++) {
		int s = rand() % 16 + 1;
		map[size_y - 1][s] = 0;
	}
}

void Map::f_block() { // 3
	if (skill) {
		skill = 0;
	}
}

void Map::invisible() // 4
{
	if (!skill) {
		time_now = time(NULL);
	}
	else {
		skill = 0;
	}
}

void Map::random_block() // 5
{
	if (skill) {
		skill = 0;
	}
}

void Map::turn() { // 6
	int i, j;
	int temp_map[17][18];
	genMap(temp_map);

	for (i = 0; i < size_y; i++) {
		sort(map[i] + 1, map[i] + size_x + 1);
	}
	for (i = 0; i < size_y; i++) {
		for (j = 1; j < size_x + 1; j++) {
			if (map[i][j] == 1) {
				temp_map[j - 1][size_y - i] = map[i][j];
			}
		}
	}

	genMap(map);
	for (i = 0; i < size_y; i++) {
		for (j = 1; j < size_x + 1; j++) {
			map[i][j] = temp_map[i][j];
		}
	}
}

void Map::delete_line()
{
	for (int i = 1; i <= 16; i++) {
		map[15][i] = map[14][i] = 0;
	}
	for (int i = 1; i <= 16; i++) {
		for (int j = 15; j >= 2; j--) {
			map[j][i] = map[j - 2][i];
		}
	}
	for (int i = 1; i <= 16; i++) {
		map[0][i] = map[1][i] = 0;
	}
}
