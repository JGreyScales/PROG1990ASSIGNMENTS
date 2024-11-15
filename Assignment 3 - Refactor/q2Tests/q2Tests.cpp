#include "pch.h"
#include "CppUnitTest.h"

extern "C" double sum_of_smallest_and_largest(double[], int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace q2Tests
{
	TEST_CLASS(q2Tests)
	{
	public:
		
		TEST_METHOD(singleElement)
		{
			double arr[1] = { 2 };
			int length = sizeof(arr) / sizeof(arr[0]);

			Assert::AreEqual(4.0, sum_of_smallest_and_largest(arr, length));
		}

		TEST_METHOD(negativeNumbers)
		{
			double arr[] = {-2, -1, -6, 2, 3, 0};
			int length = sizeof(arr) / sizeof(arr[0]);

			Assert::AreEqual(-3.0, sum_of_smallest_and_largest(arr, length));
		}

		TEST_METHOD(fractionalNumbers)
		{
			double arr[] = { -2.1, -1.6, -6.1, 20, 3, 0 };
			int length = sizeof(arr) / sizeof(arr[0]);

			Assert::AreEqual(13.9, sum_of_smallest_and_largest(arr, length));
		}
	};
}
