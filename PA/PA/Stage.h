#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <ctime>

class Stage
{
public:
	int speed; //숫자가 낮을수록 속도가 빠르다
	int stick_rate; //막대가 나오는 확률 0~99 , 99면 막대기만 나옴
	int clear_line;
public:
	Stage();
	~Stage();
};

