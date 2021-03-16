#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Stack.h"

BiTree CreateTNode(char data) {
	BiTree root = (BiTree)malloc(sizeof(BiTNode));
	root->Data = data;
	root->LChild = NULL;
	root->RChild = NULL;
	return root;
}

void VisitTNode(char data) {
	printf(" %c ", data);
}

// 第6章 树
// 6.4.1 p128

// 算法 6.1
// 先序遍历
void PreOrder(BiTree root) {
	if (!root) {
		return;
	}

	VisitTNode(root->Data);
	PreOrder(root->LChild);
	PreOrder(root->RChild);
}

// 算法 6.2
// 中序遍历
void InOrder(BiTree root) {
	if (!root) {
		return;
	}

	PreOrder(root->LChild);
	VisitTNode(root->Data);
	PreOrder(root->RChild);
}

// 算法 6.3
// 后序遍历
void PostOrder(BiTree root) {
	if (!root) {
		return;
	}

	PreOrder(root->LChild);
	PreOrder(root->RChild);
	VisitTNode(root->Data);
}

// p129 算法6.4
// 先序非递归遍历二叉树
void PreOrderNonRecur(BiTree root) {
	if (!root) {
		return;
	}

	StackPTR stack = CreateStack();
	BiTree cur = root;
	BiTree* top;

	while (cur != NULL || !Empty_SeqStack(stack))
	{
		while (cur != NULL)
		{
			VisitTNode(cur->Data);
			Push_SeqStack(stack, &cur);
			cur = cur->LChild;
		}

		top = (BiTree*)Pop_SeqStack(stack);
		cur = (*top)->RChild;
	}
}

// p130 算法6.5
// 中序非递归遍历二叉树
void InOrderNonRecur(BiTree root) {
	if (!root) {
		return;
	}

	StackPTR stack = CreateStack();
	BiTree cur = root;
	BiTree* top;

	while (cur != NULL || !Empty_SeqStack(stack))
	{
		while (cur != NULL)
		{
			Push_SeqStack(stack, &cur);
			cur = cur->LChild;
		}

		top = (BiTree*)Pop_SeqStack(stack);
		VisitTNode((*top)->Data);
		cur = (*top)->RChild;
	}
}

// p131 算法 6.7
// 后序非递归遍历二叉树
void PostOrderNonRecur(BiTree root) {
	if (!root) {
		return;
	}

	StackPTR stack = CreateStack();
	BiTree cur = root, pre = NULL;
	BiTree* top;

	while (cur != NULL || !Empty_SeqStack(stack))
	{
		while (cur != NULL)
		{
			Push_SeqStack(stack, &cur);
			cur = cur->LChild;
		}

		top = (BiTree*)Top_SeqStack(stack);
		if ((*top)->RChild == NULL || (*top)->RChild == pre) {
			top = (BiTree*)Pop_SeqStack(stack);
			VisitTNode((*top)->Data);
			pre = *top;
		}
		else
		{
			cur = (*top)->RChild;
		}
	}
}