#include "pch.h"
#include "CppUnitTest.h"
#include "../Project.10.1/Student.cpp"
#include "../Project.10.1/Search.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10_1
{
	TEST_CLASS(UnitTest10_1)
	{
	public:

		// допоміжна функція – створює студента з указаними оцінками
		static Student Make(const char* prizv, int fiz, int mat, int inf)
		{
			Student st;
			st.prizv = prizv;
			st.kurs = 1;
			st.spec = KOMP_NAUKY;
			st.fizyka = fiz;
			st.matematyka = mat;
			st.informatyka = inf;
			return st;
		}

		// ---------- CountGoodGrades (10.1.1) ----------
		TEST_METHOD(TestCountGood_EachSubject)
		{
			Student s[4] = {
				Make("Коваль", 4, 5, 3),
				Make("Мельник", 4, 4, 3),
				Make("Шевчук", 5, 4, 4),
				Make("Бойко", 3, 4, 5) };
			int f, m, i;
			CountGoodGrades(s, 4, f, m, i);
			Assert::AreEqual(2, f); // «4» з фізики: Коваль, Мельник
			Assert::AreEqual(3, m); // «4» з математики: Мельник, Шевчук, Бойко
			Assert::AreEqual(1, i); // «4» з інформатики: Шевчук
		}

		TEST_METHOD(TestCountGood_None)
		{
			Student s[2] = { Make("Коваль", 5, 5, 5), Make("Бойко", 3, 3, 3) };
			int f = 9, m = 9, i = 9; // початкові значення мають бути обнулені
			CountGoodGrades(s, 2, f, m, i);
			Assert::AreEqual(0, f);
			Assert::AreEqual(0, m);
			Assert::AreEqual(0, i);
		}

		// ---------- PercentFiveFizMat (10.1.2) ----------
		TEST_METHOD(TestPercent_Half)
		{
			Student s[4] = {
				Make("Коваль", 5, 5, 3),  // «5» і з фізики, і з математики
				Make("Мельник", 5, 4, 5), // лише з фізики
				Make("Шевчук", 5, 5, 4),  // «5» і з фізики, і з математики
				Make("Бойко", 4, 5, 5) }; // лише з математики
			Assert::AreEqual(50.0, PercentFiveFizMat(s, 4), 1e-9);
		}

		TEST_METHOD(TestPercent_All)
		{
			Student s[2] = { Make("Коваль", 5, 5, 5), Make("Бойко", 5, 5, 3) };
			Assert::AreEqual(100.0, PercentFiveFizMat(s, 2), 1e-9);
		}

		TEST_METHOD(TestPercent_None)
		{
			Student s[2] = { Make("Коваль", 4, 5, 5), Make("Бойко", 5, 4, 5) };
			Assert::AreEqual(0.0, PercentFiveFizMat(s, 2), 1e-9);
		}

		TEST_METHOD(TestPercent_EmptyArray)
		{
			Assert::AreEqual(0.0, PercentFiveFizMat(nullptr, 0), 1e-9);
		}
	};
}
