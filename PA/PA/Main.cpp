#include <iostream>
#include "Map.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	Map map;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 50; i++) {
		map.map[rand() % 16][rand() % 16 + 1] = 1;
	}
	map.showMap();
	cout << "========================\n";
	map.turn();
	map.showMap();

	Game game;
	game.play_game();
	return 0;
}