// заголовний файл Ц посл≥довний пошук в масив≥ структур
#pragma once
#include "Student.h"

// 10.1.1: п≥драховуЇ к≥льк≥сть оц≥нок Ђдобреї (4) з кожного предмету;
//         результати повертаЇ через параметри-посиланн€
void CountGoodGrades(const Student* s, const int N, int& fizyka, int& matematyka, int& informatyka);

// 10.1.2: обчислюЇ процент студент≥в, €к≥ отримали ≥ з ф≥зики, ≥ з математики оц≥нку Ђ5ї
double PercentFiveFizMat(const Student* s, const int N);
