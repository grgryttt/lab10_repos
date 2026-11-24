// Лабораторна робота № 10.1. Послідовний пошук в масиві структур (рівень А, варіант 30)
#include <iostream>
#include <iomanip>
#include <Windows.h>              // забезпечення відображення кирилиці
#include "Student.h"
#include "Input.h"
#include "Create.h"
#include "Print.h"
#include "Search.h"
using namespace std;

int main()
{                                 // забезпечення відображення кирилиці:
	SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N = ReadInt("Введіть кількість студентів N (1-1000): ", 1, 1000);

	Student* s = new Student[N]();   // динамічний масив структур (обнулений)
	bool created = false;            // чи вже введено дані

	int fiz, mat, inf;
	double proc;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - кількість оцінок \"добре\" з кожного предмету" << endl;
		cout << " [4] - процент студентів, які отримали і з фізики," << endl;
		cout << "       і з математики оцінку \"5\"" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		menuItem = ReadInt("Введіть значення: ", 0, 4);
		cout << endl << endl << endl;

		if (menuItem >= 2 && menuItem <= 4 && !created)
		{
			cout << "Спочатку введіть дані (пункт [1])!" << endl;
			continue;
		}

		switch (menuItem)
		{
		case 1:
			Create(s, N);
			created = true;
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			CountGoodGrades(s, N, fiz, mat, inf);
			cout << "Кількість оцінок \"добре\":" << endl;
			cout << "   з фізики:      " << fiz << endl;
			cout << "   з математики:  " << mat << endl;
			cout << "   з інформатики: " << inf << endl;
			break;
		case 4:
			proc = PercentFiveFizMat(s, N);
			cout << "Процент студентів, які отримали і з фізики, і з математики оцінку \"5\":" << endl;
			cout << fixed << setprecision(2) << proc << "%" << endl;
			break;
		case 0:
			break;
		}
	} while (menuItem != 0);

	delete[] s;
	return 0;
}
