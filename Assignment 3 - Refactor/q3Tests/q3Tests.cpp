#include "pch.h"
#include "CppUnitTest.h"

extern "C" int multiply_two_arrays_into_third(int[], int[], int, int[]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace q3Tests
{
	TEST_CLASS(q3Tests)
	{
	public:
		
		TEST_METHOD(firstNegativeValues)
		{
			int arr[] = { -2, -4, -5 ,-8 };
			int arr2[] = { 1, 0, 4, 6 };
			int returnArry[] = { 0, 0, 0 ,0 };

			int length = sizeof(arr) / sizeof(arr[0]);

			multiply_two_arrays_into_third(arr, arr2, length, returnArry);
			
			int expectedAnswer[]  = {-2, 0, -20, -48};

			for (int i = 0; i < length; i++) {
				
				Assert::AreEqual(expectedAnswer[i], returnArry[i]);

			}
		}
		
		TEST_METHOD(secondNegativeValues)
		{
			int arr[] = { 2, 4, 5 ,8 };
			int arr2[] = { -1, -0, -4, -6 };
			int returnArry[] = { 0, 0, 0 ,0 };

			int length = sizeof(arr) / sizeof(arr[0]);

			multiply_two_arrays_into_third(arr, arr2, length, returnArry);
			
			int expectedAnswer[]  = {-2, 0, -20, -48};

			for (int i = 0; i < length; i++) {
				
				Assert::AreEqual(expectedAnswer[i], returnArry[i]);

			}
		}

		TEST_METHOD(allNegativeValues)
		{
			int arr[] = { -2, -4, -5 , -8 };
			int arr2[] = { -1, -0, -4, -6 };
			int returnArry[] = { 0, 0, 0 ,0 };

			int length = sizeof(arr) / sizeof(arr[0]);

			multiply_two_arrays_into_third(arr, arr2, length, returnArry);

			int expectedAnswer[] = { 2, 0, 20, 48 };

			for (int i = 0; i < length; i++) {

				Assert::AreEqual(expectedAnswer[i], returnArry[i]);

			}
		}

		TEST_METHOD(allpositiveValues)
		{
			int arr[] = { 2, 4, 5 , 8, 24};
			int arr2[] = { 1, 0, 4, 6, 53 };
			int returnArry[] = { 0, 0, 0 ,0, 0 };

			int length = sizeof(arr) / sizeof(arr[0]);

			multiply_two_arrays_into_third(arr, arr2, length, returnArry);

			int expectedAnswer[] = { 2, 0, 20, 48, 1272 };

			for (int i = 0; i < length; i++) {

				Assert::AreEqual(expectedAnswer[i], returnArry[i]);

			}
		}
	};
}
