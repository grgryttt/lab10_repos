// файл реалізації – формування масиву структур
#include <iostream>
#include "Create.h"
#include "Input.h"
using namespace std;

void Create(Student* s, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;

		s[i].prizv = ReadSurname("     прізвище: ", 15);
		s[i].kurs = ReadInt("     курс (1-6): ", 1, 6);
		s[i].spec = (Specialnist)ReadInt(
			"     спеціальність (0 - Комп'ютерні науки, 1 - Інформатика,\n"
			"                    2 - Математика та економіка, 3 - Фізика та інформатика,\n"
			"                    4 - Трудове навчання): ", 0, SPEC_COUNT - 1);
		s[i].fizyka = ReadInt("     оцінка з фізики (1-5): ", 1, 5);
		s[i].matematyka = ReadInt("     оцінка з математики (1-5): ", 1, 5);
		s[i].informatyka = ReadInt("     оцінка з інформатики (1-5): ", 1, 5);
		cout << endl;
	}
}
