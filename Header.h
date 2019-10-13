#pragma once // 5 б е
#include <iostream> // Подключаем заголовочный файл ввода-вывода
#include <fstream> // Подключаем заголовочный файл для работы с файлами
#include <string> // Подключаем заголовочный файл для работы со строками
#include <ctime> // Подключаем заголовочный файл для работы со временем и датой
using namespace std; // Подключаем пространство имен std
class Teachers { //	Объявляем класс
public:
	string FIO;
	string department;
	string rank;
	string degree;
};
// Объявляем все функции
void ClassInitialization(Teachers *obj, int N); 
void BubbleSorting(Teachers *obj, int N);
void QuickSorting(Teachers *obj, int first, int last);
int CreateDataBase();
int InputM();
int InputN();
void CreateNewFile(Teachers *obj, int N); 
bool operator>(Teachers &a, Teachers &b);

