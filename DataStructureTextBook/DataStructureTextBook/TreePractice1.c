#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "Tree.h"
#include "Stack.h"

int Max(int num1, int num2) {
	if (num1 == num2) {
		return num1;
	}
	return num1 > num2 ? num1 : num2;
}

// P132 遍历算法应用

// 1. 统计一棵二叉树有多少节点
int GetTreeNodeCount(BiTree root) {
	if (root == NULL) {
		return 0;
	}
	return GetTreeNodeCount(root->LChild) + GetTreeNodeCount(root->RChild) + 1;
}


// 2. 统计一棵二叉树有多少叶子节点
int GetTreeLeafNodeCount(BiTree root) {
	if (root == NULL) {
		return 0;
	}
	if (root->LChild == NULL && root->RChild == NULL) {
		return 1;
	}
	return GetTreeLeafNodeCount(root->LChild) + GetTreeLeafNodeCount(root->RChild);
}


// 3. 输出一棵二叉树所有叶子节点
void PrintTreeLeafNodeCount(BiTree root) {
	if (root == NULL) {
		return;
	}
	if (root->LChild == NULL && root->RChild == NULL) {
		printf(" %c ", root->Data);;
	}
	PrintTreeLeafNodeCount(root->LChild);
	PrintTreeLeafNodeCount(root->RChild);
}


// 4. 计算一棵二叉树的高度
int GetTreeHeight(BiTree root) {
	if (root == NULL) {
		return 0;
	}
	if (root->LChild == NULL && root->RChild == NULL) {
		return 1;
	}

	int h1 = GetTreeHeight(root->LChild);
	int h2 = GetTreeHeight(root->RChild);
	return Max(h1, h2) + 1;
}


// 5. 求二叉树某个节点的双亲
BiTree GetTreeParent(BiTree root, BiTree find) {
	BiTree result = NULL;
	if (root == NULL) {
		return NULL;
	}
	if (find == root) {
		return NULL;
	}
	if (root->LChild == find || root->RChild == find) {
		return root;
	}

	result = GetTreeParent(root->LChild, find);
	if (result != NULL) {
		return result;
	}
	else
	{
		return GetTreeParent(root->RChild, find);
	}
}


// 6. 判定两棵二叉树是否相似
bool IsTreeSimilar(BiTree tree1, BiTree tree2) {
	if (tree1 == NULL && tree2 == NULL) {
		return true;
	}
	if (tree1 == NULL && tree2 != NULL) {
		return false;
	}
	if (tree1 != NULL && tree2 == NULL) {
		return false;
	}

	return IsTreeSimilar(tree1->LChild, tree2->LChild) && IsTreeSimilar(tree1->RChild, tree2->RChild);
}


// 7. 横向打印一棵二叉树,调用时h为0
void Horizontal(BiTree root, int h) {
	char *spaceStr = NULL;
	if (root == NULL) {
		return;
	}

	Horizontal(root->RChild, h + 1);
	for (int i = 0; i < h; i++) {
		printf(" ");
	}
	printf("%c\n", root->Data);
	Horizontal(root->LChild, h + 1);
}


// 8. 输入并建立一棵二叉树, *号代表了空节点
BiTree CreatePreTNode() {
	BiTree root;
	char data = getchar();
	if (data == '*') {
		return NULL;
	}

	root = (BiTree)malloc(sizeof(BiTNode));
	root->Data = data;
	root->LChild = CreatePreTNode();
	root->RChild = CreatePreTNode();
}