#include"nag³ówek.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

Array::Array(int X, int Y) {

	sizeX = X;
	sizeY = Y;
	arr = new int* [sizeX];
	for (int i = 0; i < sizeX; ++i) 
	{
		arr[i] = new int[sizeY];
		for (int j = 0; j < sizeY; ++j) 
		{
			arr[i][j] = i * sizeY + j;
		}

	}

}

Array::~Array() {

	/*for (int k = 0; k < sizeX; k++)
	{
		delete[] arr[k];
	}
	delete[] arr;
	*/
}

int Array::setSize(int X, int Y) {

	if (X <= 0 || Y <= 0) { return 1; }
	else if (X == sizeX && Y == sizeY) { return 0; }
	else {
		int** copy = new int* [sizeX];
		for (int i = 0; i < sizeX; i++)
		{
			copy[i] = new int[sizeY];
			for (int j = 0; j < sizeY; j++)
			{
				copy[i][j] = arr[i][j];
			}
		}

		for (int k = 0; k < sizeX; k++)
		{
			delete[] arr[k];
			arr[k] = 0;
		}
		delete[] arr;
		arr = 0;


		arr = new int* [X];
		for (int l = 0; l < X; l++)
		{
			arr[l] = new int[Y];
			for (int m = 0; m < Y; m++)
			{
				if (m < sizeY && l < sizeX)
				{
					arr[l][m] = copy[l][m];
				}
				else arr[l][m] = 0;

			}

		}

		for (int n = 0; n < sizeX ; n++)
		{
			delete[] copy[n];
		}
		delete[] copy;

		sizeX = X;
		sizeY = Y;

		return 0;
	}
}

int Array::setValue(int X, int Y, int value) {

	if (X <= sizeX && X > 0 && Y <= sizeY && Y > 0)
	{
		arr[X - 1][Y - 1] = value;
	}
	else return 1;

	return 0;
}

int Array::Save() {
	fstream plik;
	plik.open("plik.txt", ios::out);
	if (plik.good() == true)
	{
		plik << sizeX << endl;
		plik << sizeY << endl;
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				plik << arr[i][j];
				if (j < sizeY - 1) { plik << ","; }
			}
			plik << endl;
		}

		plik.close();
	}
	else return 1;
	return(0);
}
int Array::Read() {
	fstream plik;
	plik.open("plik.txt", std::ios::in);
	if (plik.good() == true) {
		string dane;
		int Xr = 1, Yr = 1;
		getline(plik, dane);
		Xr = atoi(dane.c_str());
		getline(plik, dane);
		Yr = atoi(dane.c_str());
		setSize(Xr, Yr);
		for (int i = 0; i < Xr; i++)
		{
			for (int j = 0; j < Yr-1; j++)
			{
				getline(plik, dane,',');
				arr[i][j] = atoi(dane.c_str());
			}
			getline(plik, dane);
			arr[i][Yr-1] = atoi(dane.c_str());
		}
	}
	else return 1;
	return 0;
}

int Array::sumaK(int Y) {
	int suma = 0;
	for (int i = 0; i < sizeX; i++)
	{
		suma += arr[i][Y-1];
	}
	cout << "SUMA Kolumny [" << Y << "] = " << suma << "\n";
	return 0;
}
int Array::sumaW(int X) {
	int suma = 0;
	for (int i = 0; i < sizeY; i++)
	{
		suma += arr[X-1][i];
	}
	cout << "SUMA Wiersza [" << X << "] = " << suma << "\n";
	return 0;
}
int Array::minK(int Y) {
	int min =arr[0][Y-1];
	for (int i = 1; i < sizeX; i++)
	{
		if (arr[i][Y - 1] < min)min = arr[i][Y - 1];
	}
	cout << "Minimum w kolumnie [" << Y << "] : " << min << "\n";
	return 0;
}
int Array::minW(int X) {
	int min = arr[X - 1][0];
	for (int i = 1; i < sizeY; i++)
	{
		if (arr[X - 1][i] < min)min = arr[X - 1][i];
	}
	cout << "Minimum w wierszu [" << X << "] : " << min << "\n";
	return 0;
}
int Array::maxK(int Y) {
	int max = arr[0][Y - 1];
	for (int i = 1; i < sizeX; i++)
	{
		if (arr[i][Y - 1] > max)max = arr[i][Y - 1];
	}
	cout << "Maksimum w kolumnie [" << Y << "] : " << max << "\n";
	return 0;
}
int Array::maxW(int X) {
	int max = arr[X - 1][0];
	for (int i = 1; i < sizeY; i++)
	{
		if (arr[X - 1][i] > max)max = arr[X - 1][i];
	}
	cout << "Maksimum w wierszu [" << X << "] : " << max << "\n";
	return 0;
}
float Array::sredniaK(int Y) {
	int suma = 0;
	for (int i = 0; i < sizeX; i++)
	{
		suma += arr[i][Y - 1];
	}
	float srednia = (float)suma / (float)sizeX;
	cout << "Srednia : " << srednia << "\n";
	return 0;
}
float Array::sredniaW(int X) {
	int suma = 0;
	for (int i = 0; i < sizeY; i++)
	{
		suma += arr[X - 1][i];
	}
	float srednia = (float)suma / (float)sizeY;
	cout << "Srednia : " << srednia << "\n";
	return 0;
}

void Array::Dealocate() {
	for (int k = 0; k < sizeX; k++)
	{
		delete[] arr[k];
	}
	delete[] arr;
}

