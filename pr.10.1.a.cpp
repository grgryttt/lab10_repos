// Лабораторна робота № 10.1. Послідовний пошук в масиві структур (рівень А, варіант 30)
#include <iostream>
#include <iomanip>        
#include <Windows.h>      
#include "Student.h"      
#include "Input.h"        
#include "Create.h"       
#include "Print.h"       
#include "Search.h"      
using namespace std;

int main()
{                                 
	SetConsoleCP(1251);       
	SetConsoleOutputCP(1251); 

	int N = ReadInt("Введіть кількість студентів N (1-1000): ", 1, 1000); // розмір масиву

	Student* s = new Student[N]();   // динамічний масив із N студентів; () обнуляє поля
	bool created = false;            // чи вже введено дані (спочатку ні)

	int fiz, mat, inf;               // сюди CountGoodGrades запише кількість «четвірок»
	double proc;                     // сюди запишемо відсоток

	int menuItem;                    // обраний пункт меню
	do {
		cout << endl << endl << endl;                          // відступ
		cout << "Виберіть дію:" << endl << endl;               // заголовок меню
		cout << " [1] - введення даних з клавіатури" << endl;  // пункти меню
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - кількість оцінок \"добре\" з кожного предмету" << endl;
		cout << " [4] - процент студентів, які отримали і з фізики," << endl;
		cout << "       і з математики оцінку \"5\"" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		menuItem = ReadInt("Введіть значення: ", 0, 4);        // вибір пункту (тільки 0–4)
		cout << endl << endl << endl;

		if (menuItem >= 2 && menuItem <= 4 && !created) // пункти 2–4 потребують даних
		{
			cout << "Спочатку введіть дані (пункт [1])!" << endl; // попередження
			continue;                                             // повертаємось до меню
		}

		switch (menuItem) // виконуємо обрану дію
		{
		case 1:
			Create(s, N);      // вводимо дані студентів
			created = true;    // тепер дані є
			break;
		case 2:
			Print(s, N);       // виводимо таблицю
			break;
		case 3:
			CountGoodGrades(s, N, fiz, mat, inf); // рахуємо «четвірки»
			cout << "Кількість оцінок \"добре\":" << endl;
			cout << "   з фізики:      " << fiz << endl;
			cout << "   з математики:  " << mat << endl;
			cout << "   з інформатики: " << inf << endl;
			break;
		case 4:
			proc = PercentFiveFizMat(s, N); // відсоток студентів з «5» і з фізики, і з математики
			cout << "Процент студентів, які отримали і з фізики, і з математики оцінку \"5\":" << endl;
			cout << fixed << setprecision(2) << proc << "%" << endl; // 2 цифри після коми
			break;
		case 0:
			break; // вихід: нічого не робимо, цикл завершиться
		}
	} while (menuItem != 0); // повторюємо меню, доки не обрано 0

	delete[] s;  // звільняємо динамічну пам'ять
	return 0;    // успішне завершення програми
}