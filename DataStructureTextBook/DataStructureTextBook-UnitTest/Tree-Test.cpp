#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DataStructureTextBook/Tree.c"
#include "../DataStructureTextBook/TreePractice1.c"
#include "../DataStructureTextBook/ClueTree.c"
#include "../DataStructureTextBook/create.c"
#include "../DataStructureTextBook/traverse.c"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructureTextBookUnitTest
{
	TEST_CLASS(TestBinaryTree)
	{
	public:

		/*
					A
				  /   \
				 B     C
				/     /  \
			   D     E    F
			    \     \
				G       H
		*/
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

		/*
					A
				  /   \
				 B      C
				  \    /  \
			       D   E   F
				  /       /
				 G       H
		*/
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

		/*
					A
				  /   \
				 B     C
				/     /  \
			   D     E    F
				\     \
				G       H
		*/
		BiClueTree CreateTree03() {
			BiClueTree tr1 = CreateClueNode('A');
			BiClueTree tr2 = CreateClueNode('B');
			BiClueTree tr3 = CreateClueNode('C');
			BiClueTree tr4 = CreateClueNode('D');
			BiClueTree tr5 = CreateClueNode('E');
			BiClueTree tr6 = CreateClueNode('F');
			BiClueTree tr7 = CreateClueNode('G');
			BiClueTree tr8 = CreateClueNode('H');
			tr1->LChild = tr2;
			tr1->RChild = tr3;
			tr2->LChild = tr4;
			tr3->LChild = tr5;
			tr3->RChild = tr6;
			tr4->RChild = tr7;
			tr5->RChild = tr8;
			return tr1;
		}

		TEST_METHOD(TestMethod1)
		{
			BiTree tree = CreateTree01();
			PreOrder(tree);
			AdjMatrix* map1 = CreateMap1();
			// 测试使用递归的方法，深度遍历图
			TraverseG1(map1);
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

		TEST_METHOD(TestMethod8)
		{
			BiTree tree = CreateTree01();
			PostOrderNonRecur(tree);
		}

		TEST_METHOD(TestMethod9)
		{
			BiTree tree1 = CreateTree01();
			BiTree tree2 = CreateTree01();
			bool result = IsTreeSimilar(tree1, tree2);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestMethod10)
		{
			BiTree tree = CreateTree01();
			int height = GetTreeHeight(tree);
			Assert::AreEqual(4, height);
		}

		TEST_METHOD(TestMethod11)
		{
			BiClueTree tree = CreateTree03();
			BiClueTree pre = NULL;
			InOrderClueTree(tree, &pre);
			pre = NULL;
			tree = NULL;
		}
	};
}