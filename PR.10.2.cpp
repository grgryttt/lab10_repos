// Лабораторна робота № 10.2. Впорядкування та бінарний пошук в масиві структур
// (рівень А, варіант 30)
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>              // забезпечення відображення кирилиці
#include "Student.h"
#include "Input.h"
#include "Create.h"
#include "Print.h"
#include "Sort.h"
#include "Search.h"
using namespace std;

// виводить результат бінарного пошуку
static void PrintSearchResult(const Student* s, const int pos)
{
	if (pos < 0)
	{
		cout << "Такий студент НЕ навчається (не знайдено)." << endl;
		return;
	}
	cout << "Студент навчається. Знайдено: " << s[pos].prizv
	     << ", " << s[pos].kurs << " курс, " << specStr[s[pos].spec]
	     << ", середній бал " << fixed << setprecision(2) << Average(s[pos]) << endl;
}

int main()
{                                 // забезпечення відображення кирилиці:
	SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N = ReadInt("Введіть кількість студентів N (1-1000): ", 1, 1000);

	Student* s = new Student[N]();   // динамічний масив структур (обнулений)
	int* I = nullptr;                // індексний масив (будується в пункті [4])
	bool created = false;            // чи введено дані
	bool physSorted = false;         // чи масив фізично впорядкований

	string prizv;
	int kurs;
	double avg;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl;
		cout << " [4] - індексне впорядкування та вивід за індексним масивом" << endl;
		cout << " [5] - бінарний пошук у фізично впорядкованому масиві" << endl;
		cout << " [6] - бінарний пошук в індексно впорядкованому масиві" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		menuItem = ReadInt("Введіть значення: ", 0, 6);
		cout << endl << endl << endl;

		if (menuItem >= 2 && menuItem <= 6 && !created)
		{
			cout << "Спочатку введіть дані (пункт [1])!" << endl;
			continue;
		}
		if (menuItem == 5 && !physSorted)
		{
			cout << "Спочатку виконайте фізичне впорядкування (пункт [3])!" << endl;
			continue;
		}
		if (menuItem == 6 && I == nullptr)
		{
			cout << "Спочатку виконайте індексне впорядкування (пункт [4])!" << endl;
			continue;
		}

		switch (menuItem)
		{
		case 1:
			Create(s, N);
			created = true;
			physSorted = false;      // нові дані – порядок і індекси втратили сенс
			delete[] I;
			I = nullptr;
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			Sort(s, N);
			physSorted = true;
			delete[] I;              // порядок елементів змінився – старий індексний масив недійсний
			I = nullptr;
			Print(s, N);
			break;
		case 4:
			delete[] I;
			I = IndexSort(s, N);
			PrintIndexSorted(s, I, N);
			break;
		case 5:
		case 6:
			cout << "Введіть дані для пошуку:" << endl;
			prizv = ReadSurname("     прізвище: ", 15);
			kurs = ReadInt("     курс (1-6): ", 1, 6);
			avg = ReadDouble("     середній бал (від 1 до 5, наприклад 4,33): ", 1, 5);
			cout << endl;
			if (menuItem == 5)
				PrintSearchResult(s, BinSearchPhysical(s, N, prizv, kurs, avg));
			else
				PrintSearchResult(s, BinSearchIndex(s, I, N, prizv, kurs, avg));
			break;
		case 0:
			break;
		}
	} while (menuItem != 0);

	delete[] I;
	delete[] s;
	return 0;
}
