// файл реалізації – введення даних з контролем помилок
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Input.h"
using namespace std;

// зчитує рядок із клавіатури; при завершенні потоку вводу – завершує програму
static string ReadLine(const string& prompt)
{
	string line;
	cout << prompt; // виводимо підказку
	if (!getline(cin, line)) // зчитуємо рядок; false, якщо ввід закінчився
	{
		cout << endl;
		exit(EXIT_FAILURE); // аварійно завершуємо програму
	}
	return line; // повертаємо введений рядок
}

int ReadInt(const string& prompt, const int min, const int max)
{
	while (true) // повторюємо, доки не буде коректного вводу
	{
		string line = ReadLine(prompt); // зчитуємо рядок від користувача
		char* end; // сюди запишеться місце, де зупинилось перетворення
		long v = strtol(line.c_str(), &end, 10); // перетворюємо рядок на число (десяткова система)
		while (isspace((unsigned char)*end)) end++; // пропускаємо пробіли після числа
		if (end != line.c_str()    // щось було розпізнано як число
			&& *end == '\0'        // після числа немає зайвих символів
			&& v >= min && v <= max) // число в межах діапазону
			return (int)v; // все коректно – повертаємо число
		cout << "   Помилка! Слід ввести ціле число від " << min << " до " << max << "." << endl; // повідомлення про помилку, цикл повторюється
	}
}

double ReadDouble(const string& prompt, const double min, const double max)
{
	while (true) // повторюємо, доки не буде коректного вводу
	{
		string line = ReadLine(prompt); // зчитуємо рядок від користувача
		for (size_t i = 0; i < line.size(); i++) // проходимо по кожному символу рядка
			if (line[i] == ',') line[i] = '.'; // замінюємо кому на крапку (1,5 → 1.5)
		char* end; // сюди запишеться місце, де зупинилось перетворення
		double v = strtod(line.c_str(), &end); // перетворюємо рядок на дійсне число
		while (isspace((unsigned char)*end)) end++; // пропускаємо пробіли після числа
		if (end != line.c_str()    // щось було розпізнано як число
			&& *end == '\0'        // після числа немає зайвих символів
			&& v >= min && v <= max) // число в межах діапазону
			return v; // все коректно – повертаємо число
		cout << "   Помилка! Слід ввести число від " << min << " до " << max << "." << endl; // повідомлення про помилку, цикл повторюється
	}
}

string ReadSurname(const string& prompt, const size_t maxLen)
{
	while (true) // повторюємо, доки не буде коректного вводу
	{
		string line = ReadLine(prompt); // зчитуємо рядок від користувача
		size_t b = line.find_first_not_of(" \t"); // позиція першого символу, що не є пробілом/табуляцією
		size_t e = line.find_last_not_of(" \t");  // позиція останнього такого символу
		string s = (b == string::npos) ? "" : line.substr(b, e - b + 1); // обрізаємо пробіли по краях (якщо рядок з самих пробілів – порожній)

		bool hasDigit = false; // прапорець: чи є цифра
		for (size_t i = 0; i < s.size(); i++) // перевіряємо кожен символ
			if (isdigit((unsigned char)s[i])) hasDigit = true; // знайшли цифру

		if (!s.empty() && s.size() <= maxLen && !hasDigit) // непорожнє, не задовге, без цифр
			return s; // все коректно – повертаємо прізвище
		cout << "   Помилка! Прізвище має бути непорожнім, без цифр, не довше "
			<< maxLen << " символів." << endl; // повідомлення про помилку, цикл повторюється
	}
}
