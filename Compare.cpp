// файл реалізації – порівняння структур
#include <cmath>
#include "Compare.h"
using namespace std;

int CompareAvg(const double a, const double b)
{
	if (fabs(a - b) < 0.005) // середні бали – дробові числа, тому порівнюємо з похибкою
		return 0;
	return (a < b) ? -1 : 1;
}

// порядковий номер символу (кодування Windows-1251) в українському алфавіті;
// великі й малі літери мають однаковий номер, решта символів – після літер
static int UaRank(const unsigned char c)
{
	// великі літери українського алфавіту в порядку А Б В Г Ґ Д Е Є Ж З И І Ї Й К ... Я
	static const unsigned char order[] =
	{
		0xC0, 0xC1, 0xC2, 0xC3, 0xA5, 0xC4, 0xC5, 0xAA, 0xC6, 0xC7, 0xC8, 0xB2, 0xAF, 0xC9,
		0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7,
		0xD8, 0xD9, 0xDC, 0xDE, 0xDF
	};

	unsigned char u = c;
	if (u >= 0xE0)      u -= 0x20; // а-я -> А-Я
	else if (u == 0xB4) u = 0xA5;  // ґ -> Ґ
	else if (u == 0xBA) u = 0xAA;  // є -> Є
	else if (u == 0xB3) u = 0xB2;  // і -> І
	else if (u == 0xBF) u = 0xAF;  // ї -> Ї
	else if (u >= 'a' && u <= 'z') u -= 0x20; // латиниця – також без урахування регістру

	for (int i = 0; i < (int)sizeof(order); i++)
		if (order[i] == u)
			return i;
	return 100 + u; // не літера українського алфавіту
}

int CompareSurnames(const string& a, const string& b)
{
	size_t n = (a.size() < b.size()) ? a.size() : b.size();
	for (size_t i = 0; i < n; i++)
	{
		int ra = UaRank((unsigned char)a[i]);
		int rb = UaRank((unsigned char)b[i]);
		if (ra != rb)
			return (ra < rb) ? -1 : 1;
	}
	if (a.size() == b.size()) return 0;
	return (a.size() < b.size()) ? -1 : 1; // коротше прізвище – раніше
}

bool LessPhysical(const Student& a, const Student& b)
{
	int c = CompareAvg(Average(a), Average(b));
	if (c != 0) return c < 0;
	if (a.kurs != b.kurs) return a.kurs < b.kurs;
	return CompareSurnames(a.prizv, b.prizv) > 0; // прізвища – за спаданням
}

bool LessIndex(const Student& a, const Student& b)
{
	int c = CompareAvg(Average(a), Average(b));
	if (c != 0) return c < 0;
	if (a.kurs != b.kurs) return a.kurs < b.kurs;
	return CompareSurnames(a.prizv, b.prizv) < 0; // прізвища – за зростанням
}

int CompareToKey(const Student& s, const double avg, const int kurs,
	const string& prizv, const bool surnameDesc)
{
	int c = CompareAvg(Average(s), avg);
	if (c != 0) return c;
	if (s.kurs != kurs) return (s.kurs < kurs) ? -1 : 1;
	c = CompareSurnames(s.prizv, prizv);
	return surnameDesc ? -c : c;
}
