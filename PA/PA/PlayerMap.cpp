#include "PlayerMap.h"

PlayerMap::PlayerMap(string name):
	user(Player("unkwnon"))
{
	
}

void PlayerMap::drawmap(string filename)
{
	
	ifstream is(filename);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 18; j++) {
			is >> map[i][j];
		}
	}

	string filename2 = "block.txt";
	ifstream in(filename2);
	string* temp = new string[5];
	for (int i = 0; i < 5; i++) {
		getline(in, temp[i]);
	}
	for (int i = 0; i < 10;i++) {
		for (int j = 0; j < 18; j++) {
			if (map[i][j] == 0)continue;
			
			for (int x = 0; x < 5; x++) {
				Console::gotoxy(j * 30, i * 10+x);
				cout << temp[x];
			}
		}
	}
}

PlayerMap::~PlayerMap()
{
}

bool PlayerMap::StrikeCheck()
{
	
	return map[user.y][user.x]==1?true:false;
}
void erasePlayer(int x, int y) {
	for (int i = 0; i < 15; i++) {
		Console::gotoxy(x, y+i);
		cout << "                           ";
	}
}
void PlayerMap::movePlayer()
{
	x = 0;
	y = 64;
	while (true) {
		
		
		int ch;
		if (_kbhit()) {
			ch = _getch();
			if (ch == 224) {
				ch = _getch();
				user.MovePlayer(ch);
				if (user.exMove[1] > 0) {
					switch (user.exMove[0]) {
					case 0:
					
						erasePlayer(x, y);
						if (x + 1 >= 360) {
							break;
						}
						Console::gotoxy(++x, y);
						user.MovePlayer(ch);
						break;
						
					case 4:
						erasePlayer(x, y);
						if (x - 1 <= 0) {
							break;
						}
						Console::gotoxy(--x, y);
						user.MovePlayer(ch);
						break;
					}
				}


			}
			if (ch == 13) {

			}
		}
	

		Sleep(300);
		
	};
}
