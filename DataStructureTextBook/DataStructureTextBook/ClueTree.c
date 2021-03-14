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

// 6.5.2 �����������Ļ�������

// 1. ��������������

// p139 �㷨6.18
// ������������������
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


// p139 

// �㷨6.19
// ��������������������ĳ���ڵ㣬��������ǰ��
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

// �㷨 6.20
// ��������������������ĳ���ڵ㣬�������ĺ��
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


// �㷨 6.21
// ���������������������ĵ�һ���ڵ�
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

// �㷨 6.22
// ������������������
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