// заголовний файл – функції введення даних з контролем помилок користувача
#pragma once
#include <string>

// вводить ціле число з діапазону [min; max], повторює запит при помилці
int ReadInt(const std::string& prompt, const int min, const int max);

// вводить дійсне число з діапазону [min; max] (допускається і крапка, і кома)
double ReadDouble(const std::string& prompt, const double min, const double max);

// вводить непорожнє прізвище (без цифр, не довше maxLen символів)
std::string ReadSurname(const std::string& prompt, const size_t maxLen);
