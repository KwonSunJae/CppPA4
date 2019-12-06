#include "Map.h"
#include <iostream>
#include <algorithm>
using namespace std;

Map::Map() {
	size_x = 16; size_y = 16; // x크기 y크기 16
	map = genMap();
}

int** Map::genMap() {
	int** tmap;

	tmap = new int* [size_y + 5];
	for (int i = 0; i < size_y + 5; i++) {
		tmap[i] = new int[size_x + 6];
		memset(tmap[i], 0, (size_x + 6) * sizeof(int));
	}

	for (int i = 0; i < size_y + 1; i++) {
		for (int j = 0; j < size_x + 2; j++) {
			if (i == size_y || j == 0 || j == size_x + 1) {
				tmap[i][j] = 2;
			}
		}
	}

	return tmap;
}

void Map::fast()
{
	if (!skill) {
		speed = 4;
		time_now = time(NULL);
	}
	else {
		skill = 0;
	}
}

void Map::line_up()
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

void Map::f_block() {
	if (skill) {
		skill = 0;
	}
}

void Map::invisible()
{
	if (!skill) {
		time_now = time(NULL);
	}
	else {
		skill = 0;
	}
}

void Map::random_block()
{
	if (skill) {
		skill = 0;
	}
}

void Map::turn() {
	int i, j;
	int** temp_map = genMap();

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

	for (i = 0; i < size_y + 1; i++) delete[] map[i];
	delete[] map;
	map = genMap();
	for (i = 0; i < size_y; i++) {
		for (j = 1; j < size_x + 1; j++) {
			map[i][j] = temp_map[i][j];
			cout << map[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < size_y + 1; i++) delete[] temp_map[i];
	delete[] temp_map;
}
