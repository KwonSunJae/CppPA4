#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <ctime>

class Stage
{
public:
	int speed; //���ڰ� �������� �ӵ��� ������
	int stick_rate; //���밡 ������ Ȯ�� 0~99 , 99�� ����⸸ ����
	int clear_line;
public:
	Stage();
	~Stage();
};

