#include "Map.h"
#include <iostream>
#include <algorithm>
using namespace std;

Map::Map() {
	size_x = 16; size_y = 16; // x크기 16 y크기 16
	map = genMap();
}

int** Map::genMap() {
	int** tmap;

	tmap = new int* [this->size_y+1];
	for (int i = 0; i < size_y+1; i++) {
		tmap[i] = new int[this->size_x+2];
		memset(tmap[i], 0, (this->size_x+2) * sizeof(int));
	}

	for (int i = 0; i < size_y+1; i++) {
		for (int j = 0; j < size_x+2; j++) {
			if (i == size_y || j == 0 || j == size_x+1) {
				tmap[i][j] = 2;
			}
		}
	}

	return tmap;
}

void Map::turn() {
	int i, j;
	int** temp_map = genMap();

	for (i = 0; i < size_y; i++) {
		sort(map[i]+1, map[i] + size_x+1);
	}
	for (i = 0; i < size_y; i++) {
		for (j = 1; j < size_x+1; j++) {
			if (map[i][j] == 1) {
				temp_map[j-1][size_y-i] = map[i][j];
			}
		}
	}

	for (i = 0; i < size_y+1; i++) delete[] map[i];
	delete[] map;
	map = genMap();
	for (i = 0; i < size_y; i++) {
		for (j = 1; j < size_x+1; j++) {
			map[i][j] = temp_map[i][j];
		}
	}
	for (i = 0; i < size_y+1; i++) delete[] temp_map[i];
	delete[] temp_map;

	
}

void Map::showMap() {
	for (int i = 0; i < size_y+1; i++) {
		for (int j = 0; j < size_x+2; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}
