#include "PlayerMap.h"

PlayerMap::PlayerMap(string name):
	user(Player("unkwnon"))
{
	
}

void PlayerMap::drawmap(string filename)
{
	
	ifstream is(filename);
	
	string temp;
	for (int i = 0; i < 256; i++) {
		getline(is, temp);
		cout << temp<<endl;
	}
	
}

PlayerMap::~PlayerMap()
{
}

bool PlayerMap::StrikeCheck(int x, int y)
{
	
	return map[y][x]==1?true:false;
}
void erasePlayer(int x, int y) {
	for (int i = 0; i < 15; i++) {
		Console::gotoxy(x, y+i);
		cout << "                                        ";
	}
	
}
void PlayerMap::movePlayer()
{
	x = 0;
	y = 75;
	while (true) {
		
		
		Console::gotoxy(x, y);
		user.MovePlayer(user.exMove[0], x, y);
		int ch;
		if (_kbhit()) {
			

			for (int i = 0; i < 5; i++) {
				ch = _getch();
				
				if (ch == 224) {
					ch = _getch();
					user.MovePlayer(ch, x, y);
					
					if (ch == 72) {
						erasePlayer(x, y);
						Console::gotoxy(x, y - 3); y = y - 3;

						user.MovePlayer(ch, x, y);

						Sleep(100);
						continue;
					}
					if (ch == 80) {
						erasePlayer(x, y);
						Console::gotoxy(x, y + 3); y = y + 3;
						
						user.MovePlayer(ch, x, y);
						Sleep(100);
						continue;
					}
					if (user.exMove[1] > 0) {
						switch (user.exMove[0]) {
						case 0:

							if (x + 6 >= 700) {
								break;
							}
							erasePlayer(x, y);
							x += 6;
							Console::gotoxy(x, y);
							user.MovePlayer(ch, x, y);
							break;

						case 4:

							if (x - 6 < 0) {
								break;
							}
							erasePlayer(x, y);
							x -= 6;
							Console::gotoxy(x, y);
							user.MovePlayer(ch, x, y);
							break;
						}
					}
					else {
						erasePlayer(x, y);
						Console::gotoxy(x, y);
						user.MovePlayer(ch, x, y);

					}


				}

			}
		}
		
		
		Sleep(100);
		
	};
}
