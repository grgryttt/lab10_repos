// файл реалізації – вивід масиву структур у вигляді таблиці
#include <iostream>
#include <iomanip>
#include <string>
#include "Print.h"
using namespace std;

// виводить заголовок таблиці та шапку
static void PrintHeader(const string& title)
{
	const string line(94, '=');
	const string sep(94, '-');

	cout << line << endl;
	cout << "| " << setw(90) << left << title << " |" << endl;
	cout << line << endl;
	cout << "| " << setw(3) << right << "№"
	     << " | " << setw(15) << left << "Прізвище"
	     << " | " << setw(4) << right << "Курс"
	     << " | " << setw(23) << left << "Спеціальність"
	     << " | " << setw(6) << right << "Фізика"
	     << " | " << setw(10) << "Математика"
	     << " | " << setw(11) << "Інформатика" << " |" << endl;
	cout << sep << endl;
}

// виводить один рядок таблиці
static void PrintRow(const Student& st, const int number)
{
	cout << "| " << setw(3) << right << number
	     << " | " << setw(15) << left << st.prizv
	     << " | " << setw(4) << right << st.kurs
	     << " | " << setw(23) << left << specStr[st.spec]
	     << " | " << setw(6) << right << st.fizyka
	     << " | " << setw(10) << st.matematyka
	     << " | " << setw(11) << st.informatyka << " |" << endl;
}

void Print(const Student* s, const int N)
{
	PrintHeader("СПИСОК СТУДЕНТІВ");
	for (int i = 0; i < N; i++)
		PrintRow(s[i], i + 1);
	cout << string(94, '=') << endl << endl;
}

void PrintIndexSorted(const Student* s, const int* I, const int N)
{
	PrintHeader("СПИСОК СТУДЕНТІВ (індексне впорядкування)");
	for (int i = 0; i < N; i++)
		PrintRow(s[I[i]], i + 1);
	cout << string(94, '=') << endl << endl;
}
