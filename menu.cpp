#include"nag³ówek.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int GetInput()
{
    int choice;
    cin >> choice;
    return choice;
}

void DisplayMainMenu()
{
    cout << "Main Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Resize Array\n";
    cout << "2 - Options\n";
    cout << "3 - Quit\n";
    cout << "Selection: ";
}

void DisplayOptionsMenu()
{
    cout << "Options Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Set Value\n";
    cout << "2 - Save\n";
    cout << "3 - Read\n";
    cout << "4 - Dzialania na Kolumnach\n";
    cout << "5 - Dzialania na Wierszach\n";
    cout << "6 - Back\n";
    cout << "Selection: ";
}
void DisplayOptionsKolumn(int kolumna)
{
    cout << "Options Menu ( Kolumna :"<< kolumna << " )";
    cout << "Please make your selection\n";
    cout << "1 - Suma\n";
    cout << "2 - Minimum\n";
    cout << "3 - Maximum\n";
    cout << "4 - Srednia\n";
    cout << "5 - Back\n";
    cout << "Selection: ";
}
void DisplayOptionsWierszy(int wiersz)
{
    cout << "Options Menu ( Wiersz :"<<wiersz<<" )";
    cout << "Please make your selection\n";
    cout << "1 - Suma\n";
    cout << "2 - Minimum\n";
    cout << "3 - Maximum\n";
    cout << "4 - Srednia\n";
    cout << "5 - Back\n";
    cout << "Selection: ";
}
void OptionsK(Array arr, int kolumna)
{
    int choice = 0;
    do
    {
        system("cls");
        arr.Show();
        DisplayOptionsKolumn(kolumna);
        choice = GetInput();
        switch (choice)
        {
        case 1:
            arr.sumaK(kolumna);
            system("PAUSE");
            break;
        case 2:
            arr.minK(kolumna);
            system("PAUSE");
            break;
        case 3:
            arr.maxK(kolumna);
            system("PAUSE");
            break;
        case 4:
            arr.sredniaK(kolumna);
            system("PAUSE");
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (choice != 5);
}
void OptionsW(Array arr, int wiersz)
{
    int choice = 0;
    do
    {
        system("cls");
        arr.Show();
        DisplayOptionsWierszy(wiersz);
        choice = GetInput();
        switch (choice)
        {
        case 1:
            arr.sumaW(wiersz);
            system("PAUSE");
            break;
        case 2:
            arr.minW(wiersz);
            system("PAUSE");
            break;
        case 3:
            arr.maxW(wiersz);
            system("PAUSE");
            break;
        case 4:
            arr.sredniaW(wiersz);
            system("PAUSE");
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (choice != 5);
}
void Options(Array arr)
{
    int choice = 0;
    do
    {
        system("cls");
        arr.Show();
        DisplayOptionsMenu();
        choice = GetInput();
        switch (choice)
        {
        case 1:
            int a, b, c;
            cout << "Column: ";
            cin >> a;
            cout << "Row: ";
            cin >> b;
            cout << "Cell[" << a << "][" << b << "]: ";
            cin >> c;
            if (arr.setValue(b, a, c)){ cout << "Nie istnieje taka komorka! ";    system("PAUSE"); }
            break;
        case 2:
            cout << "Saving...";
            if (arr.Save())cout << "Save Failed ";
            else cout << "Save Succes ";
            system("PAUSE");
            break;
        case 3:
            cout << "Reading...";
            if (arr.Read())cout << "Read Failed ";
            else cout << "Read Succes ";
            system("PAUSE");
            break;
        case 4:
            cout << "Wybierz Kolumne : ";
            int d;
            cin >> d;
            OptionsK(arr,d);
            break;
        case 5:
            cout << "Wybierz Wiersz : ";
            int e;
            cin >> e;
            OptionsW(arr, e);
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (choice != 6);
}

int menu(Array arr)
{
    int choice = 0;

    do
    {
        system("cls");
        arr.Show();
        DisplayMainMenu();
        choice = GetInput();
        switch (choice) {
        case 1:
            int a, b;
            cout << "Number of Wierszy: ";
            cin >> a;
            cout << "Number of Kolumn: ";
            cin >> b;
            if (arr.setSize(a, b)){ cout << "Podane wartoœci mniejsze od 1!"; system("PAUSE");}
            break;
        case 2:
            Options(arr);
            break;
        case 3:
            cout << "Goodbye!";
            break;

        default:
            break;
        }
    } while (choice != 3);
    system("PAUSE");
    return 0;
}
