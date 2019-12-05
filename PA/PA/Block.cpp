#include "Block.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Block::gen_random_block()
{
	memset(block[8], 0, sizeof(bool) * 4 * 4 * 4);
	for (int m = 0; m < 4; m++) {
		for (int i = 1; i < 3; i++) {
			for (int j = 1; j < 3; j++) {
				block[8][m][i][j] = 1;
			}
		}
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < 4; i++) {
		int x = rand() % 4;
		int y;
		if (x == 0 || x == 3) {
			y = rand() % 4;
			block[8][0][x][y] = 1;
			block[8][1][y][3 - x] = 1;
			block[8][2][3 - x][3 - y] = 1;
			block[8][3][3 - y][x] = 1;
		}
		else {
			y = rand() % 2;
			if (y == 0) {
				block[8][0][x][0] = 1;
				block[8][1][0][3 - x] = 1;
				block[8][2][3 - x][3] = 1;
				block[8][3][3][x] = 1;
			}
			else {
				block[8][0][x][3] = 1;
				block[8][1][3][3 - x] = 1;
				block[8][2][3 - x][0] = 1;
				block[8][3][0][x] = 1;
			}
		}
	}
}
