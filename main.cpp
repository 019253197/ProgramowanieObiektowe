#include"nag³ówek.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

	Array arr(4, 5);
	menu(arr);
	arr.Dealocate();
	return 0;
}