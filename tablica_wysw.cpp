#include"nag³ówek.h"
#include <iostream>

using namespace std;

int Array::Show() {
	for (int i = 0; i < sizeX; ++i)
	{
		for (int j = 0; j < sizeY; ++j)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}