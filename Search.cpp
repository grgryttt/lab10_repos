// файл реалізації – послідовний пошук в масиві структур
#include "Search.h" // оголошення функцій цього модуля (і структури Student)

// рахує, скільки студентів мають оцінку 4 з кожного предмету
// результати повертаються через параметри-посилання (int&)
void CountGoodGrades(const Student* s, const int N, int& fizyka, int& matematyka, int& informatyka)
{
	fizyka = matematyka = informatyka = 0; // обнуляємо всі три лічильники
	for (int i = 0; i < N; i++) // послідовний перегляд всього масиву
	{
		if (s[i].fizyka == 4)      fizyka++;      // оцінка 4 з фізики → збільшуємо лічильник
		if (s[i].matematyka == 4)  matematyka++;  // те саме для математики
		if (s[i].informatyka == 4) informatyka++; // те саме для інформатики
	}
}

// повертає, який відсоток студентів має «5» і з фізики, і з математики
double PercentFiveFizMat(const Student* s, const int N)
{
	if (N <= 0)
		return 0.0; // порожній масив – ділити на нуль не можна

	int k = 0; // кількість студентів з «5» і з фізики, і з математики
	for (int i = 0; i < N; i++) // перегляд усього масиву
		if (s[i].fizyka == 5 && s[i].matematyka == 5) // обидві умови одночасно
			k++; // знайшли такого студента

	return 100.0 * k / N; // відсоток; 100.0 робить ділення дробовим
}
