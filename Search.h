// заголовний файл – бінарний пошук в масиві структур
#pragma once
#include <string>
#include "Student.h"

// бінарний пошук студента (прізвище, курс, середній бал) у ФІЗИЧНО впорядкованому масиві s
// (див. Sort); повертає номер елемента масиву або -1, якщо студента не знайдено
int BinSearchPhysical(const Student* s, const int N,
	const std::string& prizv, const int kurs, const double avg);

// бінарний пошук студента (прізвище, курс, середній бал) в масиві s, ІНДЕКСНО впорядкованому
// за допомогою індексного масиву I (див. IndexSort); повертає номер елемента масиву s
// або -1, якщо студента не знайдено
int BinSearchIndex(const Student* s, const int* I, const int N,
	const std::string& prizv, const int kurs, const double avg);
