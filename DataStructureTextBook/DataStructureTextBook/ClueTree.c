#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "Tree.h"
#include "Stack.h"

BiClueTree CreateClueNode(char data) {
	BiClueTree root = (BiClueTree)malloc(sizeof(BiClueTree));
	root->Data = data;
	root->LChild = NULL;
	root->RChild = NULL;
	return root;
}

// 构造中序线索二叉树
void InOrderClueTree(BiClueTree root, BiClueTree *pre) {
	if (root == NULL) {
		return;
	}

	InOrderClueTree(root->LChild, pre);
	if ((*pre) != NULL && (*pre)->RChild == NULL) {
		(*pre)->RTag = 1;
		(*pre)->RChild = root;
	}
	if (root->LChild == NULL) {
		root->LTag = 1;
		root->LChild = (*pre);
	}
	(*pre) = root;
	InOrderClueTree(root->RChild, pre);
}


// 给定中序线索二叉树中某个节点，查找它的前驱
BiClueTree GetInOrderClueTreePre(BiClueTree find) {
	if (find == NULL) {
		return NULL;
	}

	if (find->LTag == 1) {
		return find->LChild;
	}

	find = find->LChild;
	while (find->RTag == 0)
	{
		find = find->RChild;
	}
}


// 给定中序线索二叉树中某个节点，查找它的后继
BiClueTree GetInOrderClueTreePost(BiClueTree find) {
	if (find == NULL) {
		return NULL;
	}

	if (find->RTag == 1) {
		return find->RChild;
	}

	find = find->RChild;
	while (find->LTag == 0)
	{
		find = find->LChild;
	}
}


// 求中序线索二叉树遍历的第一个节点
BiClueTree GetInOrderClueTreeFirst(BiClueTree root) {
	if (root == NULL) {
		return NULL;
	}

	while (root->LTag == 0)
	{
		root = root->LChild;
	}
	return root;
}

// 中序线索二叉树遍历
void InOrderClueTreeTraverse(BiClueTree root) {
	if (root == NULL) {
		return;
	}

	BiClueTree first = GetInOrderClueTreeFirst(root), next = GetInOrderClueTreePost(first);
	printf("visit %d\n", first->Data);

	while (next != NULL)
	{
		printf("visit %d\n", next->Data);
		next = GetInOrderClueTreePost(next);
	}
}