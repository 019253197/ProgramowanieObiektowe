#include <string>

using namespace std;

class Array {
public:
    int sizeX{ 1 };
    int sizeY{ 1 };
    int** arr;
    /**
    *@param[in] X - ilo�� wierszy
    *@param[in] Y - ilo�� kolumn
    */
    Array(int X, int Y);
    ~Array();
    /**
    *@param[in] X - ilo�� wierszy
    *@param[in] Y - ilo�� kolumn
    */
    int setSize(int X, int Y);
    /**
    *@param[in] X - numer wiersza
    *@param[in] Y - numer kolumny
    *@param[in] value - warto�� do zapisania
    */
    int setValue(int X, int Y, int value);
    int Show();
    int Save();
    int Read();
    void Dealocate();
    /**
    *@param[in] Y - numer kolumny
    */
    int sumaK(int Y);
    /**
    *@param[in] X - numer wiersza
    */
    int sumaW(int X);
    /**
    *@param[in] Y - numer kolumny
    */
    int minK(int Y);
    /**
    *@param[in] X - numer wiersza
    */
    int minW(int X);
    /**
    *@param[in] Y - numer kolumny
    */
    int maxK(int Y);
    /**
    *@param[in] X - numer wiersza
    */
    int maxW(int X);
    /**
    *@param[in] Y - numer kolumny
    */
    float sredniaK(int Y);
    /**
    *@param[in] X - numer wiersza
    */
    float sredniaW(int X);
};
/**
    *@param[in] arr - obiekt 
    */
int menu(Array arr);
