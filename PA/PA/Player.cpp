#include "Player.h"
#include <sstream>
#include "Console.h"
Player::Player(string name)
{
	pname = name;
	for (int i = 0; i < 8; i++) {
		stringstream ss;
		ss << i+1;
		this->IMGfile[i] = ss.str() + ".txt";
		this->PrintPlayer(i);
	}
	
}
void Player::Print(int i,int x, int y) {
	for (int j = 0; j < 15; j++) {
		Console::gotoxy(x,y+j);
		cout << this->draw[i][j];
	}
}
void Player::MovePlayer(int i, int x, int y)
{
	switch (i) {
	case 72: // up
		PrintPlayer(this->exMove[0] + 3);
		break;
	case 80: // down
		break;
	case 75: // left

		this->exMove[0] = LS;
		Print(5 + this->exMove[1],x,y);
		this->exMove[1] = (this->exMove[1] + 1) % 2;
		break;
	case 77://right
		this->exMove[0] = RS;
		Print(1 + this->exMove[1],x,y);
		this->exMove[1] = (this->exMove[1] + 1) % 2;
		break;

	}
}
void  Player::PrintPlayer(int i) {
	string file = this->IMGfile[i];
	ifstream in(file);
	string s;
	if (in.is_open()) {
		int cont = 0;
		while (getline(in, s)) {
			draw[i][cont++] = s;
		}
	}
	else {
		cout << "파일 안열림" + file << endl;
	}
}
void Player::MovePlayer()
{
	while (true) {
		int ch;
		if (_kbhit()) {
			ch = _getch();
			if (ch == 224) {
				ch = _getch();
				switch (ch) {
				case 72: // up
					PrintPlayer(this->exMove[0]+3);
					break;
				case 80: // down
					break;
				case 75: // left
					
					this->exMove[0] = LS;
					PrintPlayer(5 + this->exMove[1]);
					this->exMove[1] = (this->exMove[1] + 1) % 2 ;
					break;
				case 77://right
					this->exMove[0] = RS;
					PrintPlayer(1+this->exMove[1]);
					this->exMove[1] = (this->exMove[1] + 1)%2;
					break;

				}
			
				
			}
			if (ch == 13) {
				
			}
		}
		else {
			PrintPlayer(this->exMove[0]==0?0:4);
			this->exMove[1] = 0;
		}
		
		Sleep(300);

	};
}

Player::~Player()
{
}
