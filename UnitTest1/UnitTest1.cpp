#include "pch.h"
#include "CppUnitTest.h"
#include"..//ap_12.2/main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestAllElementsInList)
        {
            Node* L1 = nullptr;
            insert(L1, 5);
            insert(L1, 7);
            insert(L1, 8);

            Node* L2 = nullptr;
            insert(L2, 9);
            insert(L2, 7);
            insert(L2, 8);
            insert(L2, 5);

            Assert::IsTrue(areAllElementsInList(L1, L2));
        }
	};
}
