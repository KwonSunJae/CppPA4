#include "PlayerMap.h"

PlayerMap::PlayerMap(string name):
	user(Player("unkwnon"))
{
	
}

void PlayerMap::drawmap(string filename)
{
	Console::setSizeGame();
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

int PlayerMap::StrikeCheck(int x, int y)
{
	if ((x <= 84 && y <= 36)) return 5;
	if ((x >= 126 && y <= 84) && (x <= 222 && y >= 57)) return 2;
	if ((x <= 90 && y <= 231) && (x >=12 && y >= 153)) return 1;
	if ((x >= 342 && y >= 36) && (x <= 420 && y <= 111)) return 3;
	if ((x >= 504 && y >= 120) ) return 4;
	return 0;
}
void erasePlayer(int x, int y) {
	for (int i = 0; i < 15; i++) {
		Console::gotoxy(x, y+i);
		cout << "                                        ";
	}
	
}
void ShowMat(int x, int y) {
	Console::showMatrix(x, y);
	cout <<x<< "," << y;
}
int PlayerMap::movePlayer()
{
	x = 0;
	y = 75;

	while (true) {
		
		
		
		
		for (int i = 0; i < 5; i++) {
			int ch;
			if (StrikeCheck(x, y) != 0) {
				return StrikeCheck(x, y);
			}
			if (_kbhit()) {

				ch = _getch();
				
				if (ch == 224) {
					ch = _getch();
					user.MovePlayer(ch, x, y);
					
					if (ch == 72) {
						if (y - 3 < 0)continue;
						erasePlayer(x, y);
						Console::gotoxy(x, y - 3); y = y - 3;

						user.MovePlayer(ch, x, y);

						
						continue;
					}
					if (ch == 80) {
						if (y + 3 > 240)continue;
						erasePlayer(x, y);
						Console::gotoxy(x, y + 3); y = y + 3;

						user.MovePlayer(ch, x, y);
						
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
						user.MovePlayer(user.exMove[0] == 0 ? 0 : 4, x, y);

					}


				}


			}
			else {
				user.Print(user.exMove[0] == 0 ? 0 : 4, x, y);
				user.exMove[1] = 0;
			}

		}
		
		Sleep(100);
		
	};
}
