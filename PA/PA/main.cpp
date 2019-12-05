#include "PlayerMap.h"
int main() {
	Player p("s");
	Console a;
	PlayerMap m("d");
	a.setSizeGame();
	m.drawmap("map1.txt");
	m.movePlayer();

}