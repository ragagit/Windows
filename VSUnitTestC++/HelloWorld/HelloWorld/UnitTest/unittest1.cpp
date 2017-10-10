#include "stdafx.h"
#include "CppUnitTest.h"
#include "../HelloWorld.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethodGetTwo)
		{
			Assert::AreEqual(2, HelloWorld::getTwo());
		}

		TEST_METHOD(TestMethodGetN)
		{
			HelloWorld hw = HelloWorld();
			Assert::AreNotEqual(0, hw.getN());
		}
	};
}