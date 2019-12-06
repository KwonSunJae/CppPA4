#include "PlayerMap.h"
#include "SoundManager.h"
#include "Menu.h"
#include "Console.h"
#include "UserManager.h"
int main() {
	Menu mn;
	mn.printPressStart();
	system("cls");
	mn.menuSel();
	Console a;
	a.setSizeStory();
	Player p("s");
	PlayerMap m("d");
	a.setSizeGame();
	m.drawmap("maap.txt");
	m.movePlayer();

}