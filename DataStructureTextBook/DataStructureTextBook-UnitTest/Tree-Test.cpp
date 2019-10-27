#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DataStructureTextBook/Tree.c"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructureTextBookUnitTest
{
	TEST_CLASS(TestBinaryTree)
	{
	public:

		BiTree CreateTree01() {
			BiTree tr1 = CreateTNode('A');
			BiTree tr2 = CreateTNode('B');
			BiTree tr3 = CreateTNode('C');
			BiTree tr4 = CreateTNode('D');
			BiTree tr5 = CreateTNode('E');
			BiTree tr6 = CreateTNode('F');
			BiTree tr7 = CreateTNode('G');
			BiTree tr8 = CreateTNode('H');
			tr1->LChild = tr2;
			tr1->RChild = tr3;
			tr2->LChild = tr4;
			tr3->LChild = tr5;
			tr3->RChild = tr6;
			tr4->RChild = tr7;
			tr5->RChild = tr8;
			return tr1;
		}

		BiTree CreateTree02() {
			BiTree tr1 = CreateTNode('A');
			BiTree tr2 = CreateTNode('B');
			BiTree tr3 = CreateTNode('C');
			BiTree tr4 = CreateTNode('D');
			BiTree tr5 = CreateTNode('E');
			BiTree tr6 = CreateTNode('F');
			BiTree tr7 = CreateTNode('G');
			BiTree tr8 = CreateTNode('H');
			tr1->LChild = tr2;
			tr1->RChild = tr3;
			tr2->RChild = tr4;
			tr3->LChild = tr5;
			tr3->RChild = tr6;
			tr4->LChild = tr7;
			tr6->LChild = tr8;
			return tr1;
		}

		TEST_METHOD(TestMethod1)
		{
			BiTree tree = CreateTree01();
			PreOrder(tree);
		}

		TEST_METHOD(TestMethod2)
		{
			BiTree tree = CreateTree01();
			InOrder(tree);
		}

		TEST_METHOD(TestMethod3)
		{
			BiTree tree = CreateTree01();
			PostOrder(tree);
		}

		TEST_METHOD(TestMethod4)
		{
			BiTree tree = CreateTree02();
			PreOrder(tree);
		}

		TEST_METHOD(TestMethod5)
		{
			BiTree tree = CreateTree02();
			InOrder(tree);
		}

		TEST_METHOD(TestMethod6)
		{
			BiTree tree = CreateTree02();
			PostOrder(tree);
		}

		TEST_METHOD(TestMethod7)
		{
			BiTree tree = CreateTree01();
			PreOrderNonRecur(tree);
		}
	};
}