#include "PlayerMap.h"
#include "SoundManager.h"
#include "Menu.h"
#include "Console.h"
#include "UserManager.h"
#include "Game.h"
int main() {
	Menu mn;
	mn.printPressStart();
	system("cls");
	mn.menuSel();
	Console a;
	a.setSizeStory();
	Game game;
	game.play_game();
}