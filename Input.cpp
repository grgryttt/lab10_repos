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
	cout << prompt;
	if (!getline(cin, line))
	{
		cout << endl;
		exit(EXIT_FAILURE);
	}
	return line;
}

int ReadInt(const string& prompt, const int min, const int max)
{
	while (true)
	{
		string line = ReadLine(prompt);
		char* end;
		long v = strtol(line.c_str(), &end, 10);
		while (isspace((unsigned char)*end)) end++; // пропускаємо пробіли в кінці
		if (end != line.c_str() && *end == '\0' && v >= min && v <= max)
			return (int)v;
		cout << "   Помилка! Слід ввести ціле число від " << min << " до " << max << "." << endl;
	}
}

double ReadDouble(const string& prompt, const double min, const double max)
{
	while (true)
	{
		string line = ReadLine(prompt);
		for (size_t i = 0; i < line.size(); i++)
			if (line[i] == ',') line[i] = '.'; // кома як десятковий роздільник
		char* end;
		double v = strtod(line.c_str(), &end);
		while (isspace((unsigned char)*end)) end++;
		if (end != line.c_str() && *end == '\0' && v >= min && v <= max)
			return v;
		cout << "   Помилка! Слід ввести число від " << min << " до " << max << "." << endl;
	}
}

string ReadSurname(const string& prompt, const size_t maxLen)
{
	while (true)
	{
		string line = ReadLine(prompt);
		size_t b = line.find_first_not_of(" \t");
		size_t e = line.find_last_not_of(" \t");
		string s = (b == string::npos) ? "" : line.substr(b, e - b + 1); // без пробілів по краях

		bool hasDigit = false;
		for (size_t i = 0; i < s.size(); i++)
			if (isdigit((unsigned char)s[i])) hasDigit = true;

		if (!s.empty() && s.size() <= maxLen && !hasDigit)
			return s;
		cout << "   Помилка! Прізвище має бути непорожнім, без цифр, не довше "
		     << maxLen << " символів." << endl;
	}
}
