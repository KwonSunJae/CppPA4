#pragma once
#include "TxtLayout.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

class Menu : public TxtLayout
{
public:
	void printPressStart();
	int menuSel();
};
/// 200 ��
/// 124 �� ���� �ؽ�Ʈ