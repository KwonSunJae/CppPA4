#include "Utility.h"
#include <conio.h>
using namespace std;
int Utility::getKey()
{
	char ch = _getch();
	if (ch == -32) {
		ch = _getch();
		switch (ch) {
		case 72:
			return KEY_UP;
		case 80:
			return KEY_DOWN;
		case 75:
			return KEY_LEFT;
		case 77:
			return KEY_RIGHT;
		}
	}
	if (ch == 32)
		return KEY_SPACE;
	if (ch == 27)
		return KEY_ESC;
	if (ch == 13)
		return KEY_ENTER;
}
