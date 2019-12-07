#include "MichinSi.h"
#include "UserManager.h"
#include "PlayerMap.h"
#include "Game.h"
#include "Dialog.h"
#include "Menu.h"
MichinSi::MichinSi()
{
}

MichinSi::~MichinSi()
{
}

void MichinSi::Execute()
{
	bool isCl[8] = { 0, };
	int id;
	UserManager uM;
	SoundManager s;
	Menu menu;
	Game g;
	Dialog d;
	menu.printPressStart();
	PlayerMap m("maap.txt");
	while (true) {
		s.menuSND();
		int sel;
		sel = menu.menuSel();
		switch (sel) {
		case 0:
			uM.newCurrUser(uM.enterName());
			/////////// 프롤로그///////////
			d.openPrint();
			/////////// 튜토리얼////////////
			m.drawmap("maap.txt");
			while (true) {
				if (m.movePlayer() != 0) {
					Console::setSizeDIAL();
					d.OroPrint();
					g.level = 0;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.OroClear();
						isCl[0] = true;
						g.help_skills[0] = 1;
						break;
					}
					else {
						Console::setSizeDIAL();
						d.OroFail();
					}
				}
			}
			m.x = 12;
			m.y = 75;
			////////////일감호 /////////////

			m.drawmap("maap.txt");
			m.movePlayer();
			int choice;

			while ((choice = m.movePlayer()) != 0) {
				system("cls");
				m.drawmap("maap.txt");bool s = true;

				switch (choice) {
				case 1: // 새천년관
					
					for (int i = 0; i < 5; i++) {
						if (!isCl[i]) {
							Console::setSizeSetting();
							Console::gotoxy(25, 7);
							cout << "미클리어 상태입니다. 모두 클리어해주세요!" << endl;
							Sleep(2000);
							s = false;
							break;
						}
					}
					if (!s)break;
					Console::setSizeSetting();
					Console::gotoxy(25, 7);
					cout << "새천년관으로 이동중..." << endl;
					Sleep(2000);
					Console::setSizeGame();
					m.drawmap("maap2.txt");
					Sleep(2000);
					if (!isCl[5]) {
						Console::setSizeDIAL();
						d.jmPrint();
						g.level = 5;
						if (g.play_game()) {
							Console::Color(15);
							Console::setSizeDIAL();
							d.jmClear();
							isCl[5] = true;
							g.help_skills[5] = 1;
						}
						else {
							Console::Color(15);
							Console::setSizeDIAL();
							d.jmFail();
							break;
						}
					}
					if (!isCl[6]) {
						Console::setSizeDIAL();
						d.jjPrint();
						g.level = 6;
						if (g.play_game()) {
							Console::Color(15);
							Console::setSizeDIAL();
							d.jjClear();
							isCl[6] = true;
							g.help_skills[6] = 1;
						}
						else {
							Console::Color(15);
							Console::setSizeDIAL();
							d.jjFail();
							break;
						}
					}
					if (!isCl[7]) {
						Console::setSizeDIAL();
						d.mjPrint();
						g.level = 7;
						if (g.play_game()) {
							Console::Color(15);
							Console::setSizeDIAL();
							d.mjClear();
							isCl[7] = true;
							g.help_skills[7] = 1;
							//////////////////////ENDING//////////////////////
							d.ending();
						}
						else {
							Console::Color(15);
							Console::setSizeDIAL();
							d.mjFail();
							break;
						}
					}
					
					break;

				case 2:
					if (isCl[choice - 1]) {
						Console::setSizeSetting();
						Console::gotoxy(25, 7);
						cout << "!!! 이미 클리어한 NPC 입니다" << endl;
						Sleep(2000);
						break;
					}
					////////////// 대사 ////////////////
					Console::setSizeDIAL();
					d.drPrint();
					system("cls");
					g.level = 1;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.drClear();
						isCl[choice - 1] = true;
						g.help_skills[choice - 1] = 1;
					}
					else {
						Console::Color(15);
						Console::setSizeDIAL();
						d.drFail();
					}

					break;
				case 3:
					if (isCl[choice - 1]) {
						Console::setSizeSetting();
						Console::gotoxy(25, 7);
						cout << "!!! 이미 클리어한 NPC 입니다" << endl;
						Sleep(2000);
						break;
					}
					Console::setSizeDIAL();
					d.dcPrint();
					system("cls");
					g.level = 2;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.dcClear();
						isCl[choice - 1] = true;
						g.help_skills[choice - 1] = 1;
					}
					else {
						Console::setSizeDIAL();
						d.dcFail();
					}
					break;
				case 4:
					if (isCl[choice - 1]) {
						Console::setSizeSetting();
						Console::gotoxy(25, 7);
						cout << "!!! 이미 클리어한 NPC 입니다" << endl;
						Sleep(2000);
						break;
					}
					Console::setSizeDIAL();
					d.jsPrint();
					system("cls");
					g.level = 3;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.jsClear();
						isCl[choice - 1] = true;
						g.help_skills[choice - 1] = 1;
					}
					else {
						d.jsFail();
						Console::setSizeDIAL();
					}
				case 5:
					if (isCl[choice - 1]) {
						Console::setSizeSetting();
						Console::gotoxy(25, 7);
						cout << "!!! 이미 클리어한 NPC 입니다" << endl;
						Sleep(2000);
						break;
					}
					Console::setSizeDIAL();
					d.sdPrint();
					system("cls");
					g.level = 4;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.sdClear();
						isCl[choice - 1] = true;
						g.help_skills[choice - 1] = 1;
					}
					else {
						Console::setSizeDIAL();
						d.sdFail();
					}


				}
				m.x = 10;
				m.y = 75;
				system("cls");
				m.drawmap("maap.txt");
			}

			
			break;
		case 1:
			id = uM.SetOnLoad();
			for (int i = 0; i < 8; i++) {
				if (uM.getUser(id)->getClearStr(i) == "1") {
					isCl[i] = true;
					g.help_skills[i] = 1;
				}
				else
					isCl[i] = false;
			}
			m.drawmap("maap.txt");
			while (true) {
				if (m.movePlayer() != 0) {
					if (isCl[0] == true)
						break;
					Console::setSizeDIAL();
					d.OroPrint();
					g.level = 0;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.OroClear();
						isCl[0] = true;
						g.help_skills[0] = 1;
						break;
					}
					else {
						Console::setSizeDIAL();
						d.OroFail();
					}
				}
			}
			m.x = 12;
			m.y = 75;
			////////////일감호 /////////////

			m.drawmap("maap.txt");
			m.movePlayer();
			int choice2;

			while ((choice2 = m.movePlayer()) != 0) {
				system("cls");
				m.drawmap("maap.txt"); bool s = true;

				switch (choice2) {
				case 1: // 새천년관

					for (int i = 0; i < 5; i++) {
						if (!isCl[i]) {
							Console::setSizeSetting();
							Console::gotoxy(25, 7);
							cout << "미클리어 상태입니다. 모두 클리어해주세요!" << endl;
							Sleep(2000);
							s = false;
							break;
						}
					}
					if (!s)break;
					Console::setSizeSetting();
					Console::gotoxy(25, 7);
					cout << "새천년관으로 이동중..." << endl;
					Sleep(2000);
					Console::setSizeGame();
					m.drawmap("maap2.txt");
					Sleep(2000);
					if (!isCl[5]) {
						Console::setSizeDIAL();
						d.jmPrint();
						g.level = 5;
						if (g.play_game()) {
							Console::Color(15);
							Console::setSizeDIAL();
							d.jmClear();
							isCl[5] = true;
							g.help_skills[5] = 1;
						}
						else {
							Console::Color(15);
							Console::setSizeDIAL();
							d.jmFail();
							break;
						}
					}
					if (!isCl[6]) {
						Console::setSizeDIAL();
						d.jjPrint();
						g.level = 6;
						if (g.play_game()) {
							Console::Color(15);
							Console::setSizeDIAL();
							d.jjClear();
							isCl[6] = true;
							g.help_skills[6] = 1;
						}
						else {
							Console::Color(15);
							Console::setSizeDIAL();
							d.jjFail();
							break;
						}
					}
					if (!isCl[7]) {
						Console::setSizeDIAL();
						d.mjPrint();
						g.level = 7;
						if (g.play_game()) {
							Console::Color(15);
							Console::setSizeDIAL();
							d.mjClear();
							isCl[7] = true;
							g.help_skills[7] = 1;
							//////////////////////ENDING//////////////////////
							d.ending();
						}
						else {
							Console::Color(15);
							Console::setSizeDIAL();
							d.mjFail();
							break;
						}
					}

					break;

				case 2:
					if (isCl[choice2 - 1]) {
						Console::setSizeSetting();
						Console::gotoxy(25, 7);
						cout << "!!! 이미 클리어한 NPC 입니다" << endl;
						Sleep(2000);
						break;
					}
					////////////// 대사 ////////////////
					Console::setSizeDIAL();
					d.drPrint();
					system("cls");
					g.level = 1;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.drClear();
						isCl[choice2 - 1] = true;
						g.help_skills[choice2 - 1] = 1;
					}
					else {
						Console::Color(15);
						Console::setSizeDIAL();
						d.drFail();
					}

					break;
				case 3:
					if (isCl[choice2 - 1]) {
						Console::setSizeSetting();
						Console::gotoxy(25, 7);
						cout << "!!! 이미 클리어한 NPC 입니다" << endl;
						Sleep(2000);
						break;
					}
					Console::setSizeDIAL();
					d.dcPrint();
					system("cls");
					g.level = 2;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.dcClear();
						isCl[choice2 - 1] = true;
						g.help_skills[choice2 - 1] = 1;
					}
					else {
						Console::setSizeDIAL();
						d.dcFail();
					}
					break;
				case 4:
					if (isCl[choice2 - 1]) {
						Console::setSizeSetting();
						Console::gotoxy(25, 7);
						cout << "!!! 이미 클리어한 NPC 입니다" << endl;
						Sleep(2000);
						break;
					}
					Console::setSizeDIAL();
					d.jsPrint();
					system("cls");
					g.level = 3;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.jsClear();
						isCl[choice2 - 1] = true;
						g.help_skills[choice2 - 1] = 1;
					}
					else {
						d.jsFail();
						Console::setSizeDIAL();
					}
				case 5:
					if (isCl[choice2 - 1]) {
						Console::setSizeSetting();
						Console::gotoxy(25, 7);
						cout << "!!! 이미 클리어한 NPC 입니다" << endl;
						Sleep(2000);
						break;
					}
					Console::setSizeDIAL();
					d.sdPrint();
					system("cls");
					g.level = 4;
					if (g.play_game()) {
						Console::Color(15);
						Console::setSizeDIAL();
						d.sdClear();
						isCl[choice2 - 1] = true;
						g.help_skills[choice2 - 1] = 1;
					}
					else {
						Console::setSizeDIAL();
						d.sdFail();
					}


				}
				m.x = 10;
				m.y = 75;
				system("cls");
				m.drawmap("maap.txt");
			}
			break;
		case 2:
			s.setSoundID();
			break;
		case 3:
			return;
		}
	}
	
}
