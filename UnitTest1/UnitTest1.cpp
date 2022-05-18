#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.5/Lab_12.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* top1 = NULL,
				* top2 = NULL;
			for (int i = 0; i < 5; i++)
			{
				Push(top1, i);
				Push(top2, i);
			}

			Assert::AreEqual(AreTheSame(top1, top2), true);
		}
	};
}
