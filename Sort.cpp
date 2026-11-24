// файл реал≥зац≥њ Ц ф≥зичне та ≥ндексне впор€дкуванн€
#include "Sort.h"
#include "Compare.h"

void Sort(Student* s, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)         // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (LessPhysical(s[i1 + 1], s[i1]))
			{
				tmp = s[i1];                   // фактична зм≥на пор€дку елемент≥в
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}
}

int* IndexSort(const Student* s, const int N)
{
	int* I = new int[N];
	for (int i = 0; i < N; i++)
		I[i] = i;                              // початковий ≥ндексний масив: 0, 1, 2, ...

	int tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (LessIndex(s[I[i1 + 1]], s[I[i1]]))
			{
				tmp = I[i1];                   // м≥н€Їмо м≥сц€ми лише ≥ндекси
				I[i1] = I[i1 + 1];
				I[i1 + 1] = tmp;
			}
	return I;
}
