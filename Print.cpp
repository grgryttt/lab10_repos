// файл реалізації – вивід масиву структур у вигляді таблиці
#include <iostream>
#include <iomanip>
#include <string>
#include "Print.h"
using namespace std;

void Print(const Student* s, const int N)
{
	const string line(94, '=');
	const string sep(94, '-');

	cout << line << endl;
	cout << "|" << setw(54) << right << "СПИСОК СТУДЕНТІВ" << setw(39) << "|" << endl;
	cout << line << endl;
	cout << "| " << setw(3) << right << "№"
	     << " | " << setw(15) << left << "Прізвище"
	     << " | " << setw(4) << right << "Курс"
	     << " | " << setw(23) << left << "Спеціальність"
	     << " | " << setw(6) << right << "Фізика"
	     << " | " << setw(10) << "Математика"
	     << " | " << setw(11) << "Інформатика" << " |" << endl;
	cout << sep << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1
		     << " | " << setw(15) << left << s[i].prizv
		     << " | " << setw(4) << right << s[i].kurs
		     << " | " << setw(23) << left << specStr[s[i].spec]
		     << " | " << setw(6) << right << s[i].fizyka
		     << " | " << setw(10) << s[i].matematyka
		     << " | " << setw(11) << s[i].informatyka << " |" << endl;
	}
	cout << line << endl << endl;
}
