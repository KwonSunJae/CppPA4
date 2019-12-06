#include "MichinSi.h"
#include "PlayerMap.h"
#include "Game.h"
MichinSi::MichinSi()
{
}

MichinSi::~MichinSi()
{
}

void MichinSi::Execute()
{
	Game g;
	/////////// 프롤로그///////////


	/////////// 튜토리얼////////////


	////////////일감호 /////////////
	PlayerMap m("maap.txt");
	m.drawmap("maap.txt");
	m.movePlayer();
	int choice;
	
	while ((choice=m.movePlayer())!=1) {
		system("cls");
		m.drawmap("maap.txt");

		switch (choice) {
		case 2:
			////////////// 대사 ////////////////
			system("cls");
			g.level = 1;
			g.play_game();
			break;
		case 3:
			g.level = 2;
			system("cls");
			g.play_game();
			break;
		case 4:
			g.level = 3;
			system("cls");
			g.play_game();
			break;
		case 5:
			g.level = 4;
			system("cls");
			g.play_game();
			break;

		}
		system("cls");
		m.drawmap("maap.txt");
	}

	////////////새천년관////////////


	////////////엔딩/////////////
}
