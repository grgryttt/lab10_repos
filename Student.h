// заголовний файл Ц оголошенн€ тип≥в даних: перел≥к та структура
#pragma once
#include <string>

// перел≥к Ц спец≥альност≥ студент≥в
enum Specialnist { KOMP_NAUKY, INFORMATYKA, MAT_EKONOMIKA, FIZ_INFORMATYKA, TRUDOVE };

const int SPEC_COUNT = 5; // к≥льк≥сть спец≥альностей

// назви спец≥альностей (≥ндекс = значенн€ перел≥ку)
extern const std::string specStr[SPEC_COUNT];

// структура Ц дан≥ про студента (р≥вень ј)
struct Student
{
	std::string prizv;      // пр≥звище
	int         kurs;       // курс Ц ц≥ле число
	Specialnist spec;       // спец≥альн≥сть Ц перел≥к
	int         fizyka;     // оц≥нка з ф≥зики
	int         matematyka; // оц≥нка з математики
	int         informatyka;// оц≥нка з ≥нформатики
};

// обчислюЇ середн≥й бал студента
double Average(const Student& s);
