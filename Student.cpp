// файл реалізації – назви спеціальностей та середній бал
#include "Student.h"

const std::string specStr[SPEC_COUNT] =
{
	"Комп'ютерні науки",
	"Інформатика",
	"Математика та економіка",
	"Фізика та інформатика",
	"Трудове навчання"
};

double Average(const Student& s)
{
	return (s.fizyka + s.matematyka + s.informatyka) / 3.0;
}
