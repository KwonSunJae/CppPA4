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
	y = 75;
	while (true) {
		
		Console::gotoxy(x, y);
		user.MovePlayer(user.exMove[0], x, y);
		int ch;
		if (_kbhit()) {
			ch = _getch();
			if (ch == 224) {
				ch = _getch();
				Console::gotoxy(x, y);
				user.MovePlayer(ch,x,y);
				if (user.exMove[1] > 0) {
					switch (user.exMove[0]) {
					case 0:
					
						
						if (x + 1 >= 360) {
							break;
						}
						erasePlayer(x, y);
						Console::gotoxy(++x, y);
						user.MovePlayer(ch,x,y);
						break;
						
					case 4:
						
						if (x - 1 <= 0) {
							break;
						}
						erasePlayer(x, y);
						Console::gotoxy(--x, y);
						user.MovePlayer(ch,x,y);
						break;
					}
				}


			}
			
		}
	

		Sleep(300);
		
	};
}
