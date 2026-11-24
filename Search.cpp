// файл реал≥зац≥њ Ц б≥нарний пошук
#include "Search.h"
#include "Compare.h"
using namespace std;

int BinSearchPhysical(const Student* s, const int N,
	const string& prizv, const int kurs, const double avg)
{
	int L = 0, R = N - 1;
	while (L <= R)
	{
		int m = (L + R) / 2;
		int c = CompareToKey(s[m], avg, kurs, prizv, true); // пр≥звища Ц за спаданн€м
		if (c == 0)
			return m;
		if (c < 0)
			L = m + 1;
		else
			R = m - 1;
	}
	return -1;
}

int BinSearchIndex(const Student* s, const int* I, const int N,
	const string& prizv, const int kurs, const double avg)
{
	int L = 0, R = N - 1;
	while (L <= R)
	{
		int m = (L + R) / 2;
		int c = CompareToKey(s[I[m]], avg, kurs, prizv, false); // пр≥звища Ц за зростанн€м
		if (c == 0)
			return I[m];
		if (c < 0)
			L = m + 1;
		else
			R = m - 1;
	}
	return -1;
}
