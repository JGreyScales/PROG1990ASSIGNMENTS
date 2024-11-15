#include "pch.h"
#include "CppUnitTest.h"

extern "C" void smaller_of(double*, double*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace q1Tests
{
	TEST_CLASS(q1Tests)
	{
	public:
		
		TEST_METHOD(aIsNegativeValue)
		{
			double a = -2;
			double b = 5;

			smaller_of(&a, &b);
			Assert::AreEqual(-2.0, b);
		}

		TEST_METHOD(bIsNegativeValue)
		{
			double a = 25;
			double b = -5;

			smaller_of(&a, &b);
			Assert::AreEqual(-5.0, b);
		}
		TEST_METHOD(bothAreNegativeValue)
		{
			double a = -2;
			double b = -5;

			smaller_of(&a, &b);
			Assert::AreEqual(-5.0, a);
		}

		TEST_METHOD(bothArePositiveAisCorrect)
		{
			double a = 332;
			double b = 5892;

			smaller_of(&a, &b);
			Assert::AreEqual(332.0, b);
		}

		TEST_METHOD(bothArePositiveBisCorrect)
		{
			double a = 342232;
			double b = 5892;

			smaller_of(&a, &b);
			Assert::AreEqual(5892.0, a);
		}

		TEST_METHOD(aIsFractalValue)
		{
			double a = 2.2;
			double b = 5;

			smaller_of(&a, &b);
			Assert::AreEqual(2.2, b);
		}

		TEST_METHOD(bIsFractalValue)
		{
			double a = 2;
			double b = 5.5;

			smaller_of(&a, &b);
			Assert::AreEqual(2.0, b);
		}

		TEST_METHOD(bothAreSameValue)
		{
			double a = 2.5;
			double b = 2.5;

			smaller_of(&a, &b);
			Assert::AreEqual(2.5, a);
			Assert::AreEqual(2.5, b);
		}
	};
}
