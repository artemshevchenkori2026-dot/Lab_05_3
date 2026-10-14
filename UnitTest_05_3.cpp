#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_3/Lab_05_3.cpp" // Перевір шлях до вашого файлу Lab_05_3.cpp

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest053
{
    TEST_CLASS(UnitTest053)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            // Тест 1: Для |x| >= 1
            double expected1 = (sin(1.0) + 1.0) / (pow(cos(1.0), 2) + exp(1.0));
            double actual1 = z(1.0);
            Assert::AreEqual(expected1, actual1, 0.00001);

            // Тест 2: Для |x| < 1
            double actual0 = z(0.0);
            Assert::AreEqual(1.0, actual0, 0.00001);
        }
    };
}