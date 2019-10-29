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

// 先序遍历
void PreOrder(BiTree root) {
	if (!root) {
		return;
	}

	VisitTNode(root->Data);
	PreOrder(root->LChild);
	PreOrder(root->RChild);
}

// 中序遍历
void InOrder(BiTree root) {
	if (!root) {
		return;
	}

	PreOrder(root->LChild);
	VisitTNode(root->Data);
	PreOrder(root->RChild);
}

// 后序遍历
void PostOrder(BiTree root) {
	if (!root) {
		return;
	}

	PreOrder(root->LChild);
	PreOrder(root->RChild);
	VisitTNode(root->Data);
}

// 先序遍历的非递归实现
void PreOrderNonRecur(BiTree root) {
	if (!root) {
		return;
	}

	StackPTR stack = CreateStack(sizeof(BiTNode));
	BiTree cur = root;
	BiTree* top;

	while (cur != NULL || IsStackEmpty(stack))
	{
		while (cur != NULL)
		{
			VisitTNode(cur->Data);
			Push(stack, &cur);
			cur = cur->LChild;
		}

		top = (BiTree*)Pop(stack);
		cur = (*top)->RChild;
	}
}

// 中序遍历的非递归实现
void InOrderNonRecur(BiTree root) {
	if (!root) {
		return;
	}

	StackPTR stack = CreateStack(sizeof(BiTNode));
	BiTree cur = root;
	BiTree* top;

	while (cur != NULL || IsStackEmpty(stack))
	{
		while (cur != NULL)
		{
			Push(stack, &cur);
			cur = cur->LChild;
		}

		top = (BiTree*)Pop(stack);
		VisitTNode((*top)->Data);
		cur = (*top)->RChild;
	}
}

// 后序遍历的非递归实现
void PostOrderNonRecur(BiTree root) {
	if (!root) {
		return;
	}

	StackPTR stack = CreateStack(sizeof(BiTNode));
	BiTree cur = root, pre = NULL;
	BiTree* top;

	while (cur != NULL || IsStackEmpty(stack))
	{
		while (cur != NULL)
		{
			Push(stack, &cur);
			cur = cur->LChild;
		}

		top = (BiTree*)Top(stack);
		if ((*top)->RChild == NULL || (*top)->RChild == pre) {
			top = (BiTree*)Pop(stack);
			VisitTNode((*top)->Data);
			pre = *top;
		}
		else
		{
			cur = (*top)->RChild;
		}
	}
}