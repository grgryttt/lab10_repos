// заголовний файл Ц пор≥вн€нн€ структур (ключ≥ впор€дкуванн€ та пошуку)
#pragma once
#include <string>
#include "Student.h"

// пор≥внюЇ два середн≥ бали з точн≥стю 0,005: -1 (a < b), 0 (р≥вн≥), 1 (a > b)
int CompareAvg(const double a, const double b);

// пор≥внюЇ пр≥звища за украњнським алфав≥том без урахуванн€ рег≥стру: -1, 0, 1
int CompareSurnames(const std::string& a, const std::string& b);

// ф≥зичне впор€дкуванн€: чи маЇ a сто€ти ран≥ше за b
// (середн≥й бал Ц за зростанн€м, курс Ц за зростанн€м, пр≥звище Ц за —ѕјƒјЌЌяћ)
bool LessPhysical(const Student& a, const Student& b);

// ≥ндексне впор€дкуванн€: чи маЇ a сто€ти ран≥ше за b
// (середн≥й бал Ц за зростанн€м, курс Ц за зростанн€м, пр≥звище Ц за зростанн€м)
bool LessIndex(const Student& a, const Student& b);

// пор≥внюЇ студента s ≥з ключем пошуку (середн≥й бал, курс, пр≥звище):
// < 0 Ц s розташований ран≥ше за ключ, 0 Ц зб≥гаЇтьс€, > 0 Ц п≥зн≥ше;
// surnameDesc = true, €кщо пр≥звища впор€дкован≥ за спаданн€м
int CompareToKey(const Student& s, const double avg, const int kurs,
	const std::string& prizv, const bool surnameDesc);
