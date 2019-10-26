#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DataStructureTextBook/BinaryTree.c"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructureTextBookUnitTest
{
	TEST_CLASS(TestBinaryTree)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			BiTree root = CreateTNode('A');
			BiTree left = CreateTNode('B');
			BiTree right = CreateTNode('C');
			root->LChild = left;
			root->RChild = right;
			Assert::AreEqual('C', root->RChild->data);
		}

		TEST_METHOD(TestMethod2)
		{

		}

		TEST_METHOD(TestMethod3)
		{

		}

	};
}