#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DataStructureTextBook/Stack.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructureTextBookUnitTest
{
	TEST_CLASS(TestStack)
	{
	public:

		TEST_METHOD(TestMethod_Stack01)
		{
			/*int a1 = 3;
			int a2 = 6;
			int a4 = 9;
			int *top = NULL;

			StackPTR stack = CreateStack();
			Push_SeqStack(stack, &a1);
			Push_SeqStack(stack, &a2);
			top = (int*)Top(stack);
			Assert::AreEqual(6, *top);

			Push(stack, &a4);
			Assert::AreEqual(3, stack->Count);
			top = (int*)Pop(stack);
			Assert::AreEqual(9, *top);
			Assert::AreEqual(2, stack->Count);*/
		}

		TEST_METHOD(TestMethod_Stack02)
		{
			/*BiTree tree1 = CreateTNode('A');
			BiTree tree2 = CreateTNode('B');
			BiTree result = NULL;
			StackPTR stack = CreateStack(sizeof(BiTNode));
			Push(stack, &tree1);
			Push(stack, &tree2);
			Assert::AreEqual(2, stack->Count);
			result = (BiTree)Top(stack);
			Assert::AreEqual(2, stack->Count);
			Assert::AreEqual('B', result->data);*/
		}

	};
}