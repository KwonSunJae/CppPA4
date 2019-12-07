#include "TxtLayout.h"
void TxtLayout::printTxt(const string& filename)
{
	ifstream fin(filename);
	if (fin.is_open()) {
		int num; fin >> num;
		string tmp;
		for (int i = 0; i < num; i++) {
			getline(fin, tmp);
			cout << tmp << endl;
		}
	}
}