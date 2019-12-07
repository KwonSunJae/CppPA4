#include "Dialog.h"
#include "Console.h"

void Dialog::openPrint()
{

	Console::setSizeStory();
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake2.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake3.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake4.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake5.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake6.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake7.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake8.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake9.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake10.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake11.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake12.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake13.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake14.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake15.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake16.txt");
	Sleep(100);
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("lake17.txt");
	Sleep(100);
}

void Dialog::OroPrint()
{
	Console::setSizeStory();
	for (int i = 0; i < 8; i++) {
		if (i == 7)
			Console::setSizeStory();
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(oroTxt[i].c_str());
		Sleep(100);
	}
}

void Dialog::OroClear()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(oroClear[i].c_str());
		Sleep(100);
	}
}

void Dialog::OroFail()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(oroFail[i].c_str());
		Sleep(100);
	}
}

void Dialog::drPrint()
{
	Console::setSizeStory();
	for (int i = 0; i < 6; i++) {
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(DrTxt[i].c_str());
		Sleep(100);
	}
}

void Dialog::drClear()
{
	Console::setSizeStory();
	for (int i = 0; i < 5; i++) {
		if (i == 4)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(DrClear[i].c_str());
		Sleep(100);
	}
}

void Dialog::drFail()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(DrFail[i].c_str());
		Sleep(100);
	}
}

void Dialog::dcPrint()
{
	Console::setSizeStory();
	for (int i = 0; i < 6; i++) {
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(DcTxt[i].c_str());
		Sleep(100);
	}
}

void Dialog::dcClear()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(DcClear[i].c_str());
		Sleep(100);
	}
}

void Dialog::dcFail()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(DcFail[i].c_str());
		Sleep(100);
	}
}

void Dialog::jsPrint()
{
	Console::setSizeStory();
	for (int i = 0; i < 3; i++) {
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JsTxt[i].c_str());
		Sleep(100);
	}
}

void Dialog::jsClear()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JsClear[i].c_str());
		Sleep(100);
	}
}

void Dialog::jsFail()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JsFail[i].c_str());
		Sleep(100);
	}
}

void Dialog::sdPrint()
{
	Console::setSizeStory();
	for (int i = 0; i < 6; i++) {
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(SdTxt[i].c_str());
		Sleep(100);
	}
}

void Dialog::sdClear()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(SdClear[i].c_str());
		Sleep(100);
	}
}

void Dialog::sdFail()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(SdFail[i].c_str());
		Sleep(100);
	}
}

void Dialog::jmPrint()
{
	Console::setSizeStory();
	for (int i = 0; i < 6; i++) {
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JmTxt[i].c_str());
		Sleep(100);
	}
}

void Dialog::jmClear()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3) {
			system("cls");
			printTxt("jmC4.txt");
			break;
		}
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JmClear[i].c_str());
		Sleep(100);
	}
}

void Dialog::jmFail()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JmFail[i].c_str());
		Sleep(100);
	}
}

void Dialog::jjPrint()
{
	Console::setSizeStory();
	for (int i = 0; i < 6; i++) {
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JjTxt[i].c_str());
		Sleep(100);
	}
}

void Dialog::jjClear()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JjClear[i].c_str());
		Sleep(100);
	}
}

void Dialog::jjFail()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(JjFail[i].c_str());
		Sleep(100);
	}
}

void Dialog::mjPrint()
{
	Console::setSizeStory();
	for (int i = 0; i < 6; i++) {
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(MjTxt[i].c_str());
		Sleep(100);
	}
}

void Dialog::mjClear()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(MjClear[i].c_str());
		Sleep(100);
	}
}

void Dialog::mjFail()
{
	Console::setSizeStory();
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			system("cls");
		Console::gotoxy(0, 0);
		c.playeffSND(c.DIALOG);
		printTxt(MjFail[i].c_str());
		Sleep(100);
	}
}

void Dialog::ending()
{

	SoundManager s;

	s.menuSND();

	Console::setSizeStory();
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("ending2.txt");
	Sleep(4000);
	c.playeffSND(c.DIALOG);
	printTxt("ending3.txt");
	Sleep(4000);
	///////////////////////////

	Console::setSizeStory();
	printTxt("banner1.txt");
	Console::gotoxy(0, 0);
	Sleep(1000);
	printTxt("banner2.txt"); Console::gotoxy(0, 0);
	Sleep(1000);
	printTxt("banner3.txt"); Console::gotoxy(0, 0);
	Sleep(1000);
	printTxt("banner4.txt"); Console::gotoxy(0, 0);
	Sleep(1000);
	printTxt("banner5.txt"); Console::gotoxy(0, 0);
	Sleep(1000);
	printTxt("banner6.txt"); Console::gotoxy(0, 0);
	Sleep(1000);
	printTxt("banner7.txt"); Console::gotoxy(0, 0);
	Sleep(1000);
	system("cls");
	///콘솔 세팅
	Console::setSizeSetting();
	Console::gotoxy(10, 5);
	s.playeffSND(s.MOVE);
	cout << "우";   Sleep(1000);   s.playeffSND(s.MOVE);
	cout << "리";   Sleep(1000);   s.playeffSND(s.MOVE);
	cout << "가 ";   Sleep(1000);   s.playeffSND(s.MOVE);
	cout << "남";   Sleep(1000);   s.playeffSND(s.MOVE);
	cout << "이";   Sleep(1000);   s.playeffSND(s.MOVE);
	cout << "가";   Sleep(1000);
	Sleep(3000);
	system("cls");
	///////////////////////////
	Console::setSizeStory();
	Console::gotoxy(0, 0);
	c.playeffSND(c.DIALOG);
	printTxt("ending4.txt");
	Sleep(4000);
	c.playeffSND(c.DIALOG);
	printTxt("ending.txt");
	Sleep(4000);
}
