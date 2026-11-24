#include "pch.h"
#include "CppUnitTest.h"
#include "../PR.10.2/Student.cpp"
#include "../PR.10.2/Compare.cpp"
#include "../PR.10.2/Sort.cpp"
#include "../PR.10.2/Search.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10_2
{
	TEST_CLASS(UnitTest10_2)
	{
	public:

		// допоміжна функція – створює студента
		static Student Make(const char* prizv, int kurs, int fiz, int mat, int inf)
		{
			Student st;
			st.prizv = prizv;
			st.kurs = kurs;
			st.spec = KOMP_NAUKY;
			st.fizyka = fiz;
			st.matematyka = mat;
			st.informatyka = inf;
			return st;
		}

		// тестовий масив із 5 студентів
		//   Коваль  1 курс  середній бал 4,00
		//   Гнатюк  1 курс  середній бал 4,00
		//   Шевчук  2 курс  середній бал 4,00
		//   Мельник 1 курс  середній бал 5,00
		//   Ірчак   1 курс  середній бал 3,33
		static void Fill(Student* s)
		{
			s[0] = Make("Коваль", 1, 4, 4, 4);
			s[1] = Make("Гнатюк", 1, 4, 4, 4);
			s[2] = Make("Шевчук", 2, 3, 4, 5);
			s[3] = Make("Мельник", 1, 5, 5, 5);
			s[4] = Make("Ірчак", 1, 3, 3, 4);
		}

		// ---------- Average, CompareAvg ----------
		TEST_METHOD(TestAverage)
		{
			Student st = Make("Коваль", 1, 5, 4, 4);
			Assert::AreEqual(13.0 / 3, Average(st), 1e-12);
		}

		TEST_METHOD(TestCompareAvg)
		{
			Assert::AreEqual(0, CompareAvg(13.0 / 3, 4.33)); // 4,3333 ~ 4,33
			Assert::AreEqual(-1, CompareAvg(4.0, 4.33));
			Assert::AreEqual(1, CompareAvg(5.0, 4.67));
		}

		// ---------- CompareSurnames ----------
		TEST_METHOD(TestCompareSurnames_Alphabet)
		{
			Assert::AreEqual(-1, CompareSurnames("Гнатюк", "Ґудзь"));     // Г < Ґ
			Assert::AreEqual(-1, CompareSurnames("Ґудзь", "Давиденко"));  // Ґ < Д
			Assert::AreEqual(-1, CompareSurnames("Іванов", "Яремчук"));   // І < Я
			Assert::AreEqual(-1, CompareSurnames("Иванов", "Іванов"));    // И < І
		}

		TEST_METHOD(TestCompareSurnames_IgnoreCaseAndPrefix)
		{
			Assert::AreEqual(0, CompareSurnames("КОВАЛЬ", "коваль"));
			Assert::AreEqual(-1, CompareSurnames("Коваль", "Ковальчук"));
			Assert::AreEqual(1, CompareSurnames("Ковальчук", "Коваль"));
		}

		// ---------- LessPhysical, LessIndex ----------
		TEST_METHOD(TestLess_Keys)
		{
			Student a = Make("Коваль", 1, 4, 4, 4);   // 4,00 – 1 курс
			Student b = Make("Гнатюк", 1, 4, 4, 4);   // 4,00 – 1 курс
			Student c = Make("Шевчук", 2, 3, 4, 5);   // 4,00 – 2 курс
			Student d = Make("Мельник", 1, 5, 5, 5);  // 5,00
			Assert::IsTrue(LessPhysical(a, b));   // прізвища за спаданням: Коваль раніше за Гнатюка
			Assert::IsFalse(LessIndex(a, b));     // прізвища за зростанням: Гнатюк раніше
			Assert::IsTrue(LessIndex(b, a));
			Assert::IsTrue(LessPhysical(b, c));   // курс 1 < курс 2
			Assert::IsTrue(LessIndex(c, d));      // 4,00 < 5,00
			Assert::IsFalse(LessPhysical(a, a));  // елемент не менший за себе
		}

		// ---------- Sort (фізичне впорядкування) ----------
		TEST_METHOD(TestSort_Physical)
		{
			Student s[5];
			Fill(s);
			Sort(s, 5);
			Assert::IsTrue(s[0].prizv == "Ірчак");    // 3,33
			Assert::IsTrue(s[1].prizv == "Коваль");   // 4,00, 1 курс, прізвище за спаданням
			Assert::IsTrue(s[2].prizv == "Гнатюк");
			Assert::IsTrue(s[3].prizv == "Шевчук");   // 4,00, 2 курс
			Assert::IsTrue(s[4].prizv == "Мельник");  // 5,00
		}

		// ---------- IndexSort (індексне впорядкування) ----------
		TEST_METHOD(TestIndexSort_Order)
		{
			Student s[5];
			Fill(s);
			int* I = IndexSort(s, 5);
			Assert::AreEqual(4, I[0]); // Ірчак
			Assert::AreEqual(1, I[1]); // Гнатюк
			Assert::AreEqual(0, I[2]); // Коваль
			Assert::AreEqual(2, I[3]); // Шевчук
			Assert::AreEqual(3, I[4]); // Мельник
			delete[] I;
		}

		TEST_METHOD(TestIndexSort_ArrayNotChanged)
		{
			Student s[5];
			Fill(s);
			int* I = IndexSort(s, 5);
			Assert::IsTrue(s[0].prizv == "Коваль"); // сам масив залишився без змін
			Assert::IsTrue(s[4].prizv == "Ірчак");
			delete[] I;
		}

		// ---------- BinSearchPhysical ----------
		TEST_METHOD(TestBinSearchPhysical_Found)
		{
			Student s[5];
			Fill(s);
			Sort(s, 5);
			Assert::AreEqual(2, BinSearchPhysical(s, 5, "Гнатюк", 1, 4.0));
			Assert::AreEqual(0, BinSearchPhysical(s, 5, "Ірчак", 1, 3.33)); // 3,33 ~ 10/3
			Assert::AreEqual(4, BinSearchPhysical(s, 5, "мельник", 1, 5.0)); // без урахування регістру
		}

		TEST_METHOD(TestBinSearchPhysical_NotFound)
		{
			Student s[5];
			Fill(s);
			Sort(s, 5);
			Assert::AreEqual(-1, BinSearchPhysical(s, 5, "Коваль", 2, 4.0));   // інший курс
			Assert::AreEqual(-1, BinSearchPhysical(s, 5, "Коваль", 1, 4.5));   // інший середній бал
			Assert::AreEqual(-1, BinSearchPhysical(s, 5, "Петренко", 1, 4.0)); // немає такого прізвища
		}

		// ---------- BinSearchIndex ----------
		TEST_METHOD(TestBinSearchIndex_Found)
		{
			Student s[5];
			Fill(s);
			int* I = IndexSort(s, 5);
			Assert::AreEqual(0, BinSearchIndex(s, I, 5, "Коваль", 1, 4.0));  // повертає номер у вихідному масиві
			Assert::AreEqual(2, BinSearchIndex(s, I, 5, "Шевчук", 2, 4.0));
			Assert::AreEqual(4, BinSearchIndex(s, I, 5, "Ірчак", 1, 3.33));
			delete[] I;
		}

		TEST_METHOD(TestBinSearchIndex_NotFound)
		{
			Student s[5];
			Fill(s);
			int* I = IndexSort(s, 5);
			Assert::AreEqual(-1, BinSearchIndex(s, I, 5, "Коваль", 2, 4.0));
			Assert::AreEqual(-1, BinSearchIndex(s, I, 5, "Шевчук", 2, 5.0));
			delete[] I;
		}
	};
}

