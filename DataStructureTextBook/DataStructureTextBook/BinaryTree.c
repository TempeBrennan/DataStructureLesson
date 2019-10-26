#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

BiTree CreateTNode(char data) {
	BiTree root = (BiTree)malloc(sizeof(BiTNode));
	root->data = data;
	root->LChild = NULL;
	root->RChild = NULL;
	return root;
}

void VisitTNode(char data) {
	printf(" %c ", data);
}

void PreOrder(BiTree root) {
	if (!root) {
		return;
	}

	VisitTNode(root->data);
	PreOrder(root->LChild);
	PreOrder(root->RChild);
}

void InOrder(BiTree root) {
	if (!root) {
		return;
	}

	PreOrder(root->LChild);
	VisitTNode(root->data);
	PreOrder(root->RChild);
}

void PostOrder(BiTree root) {
	if (!root) {
		return;
	}

	PreOrder(root->LChild);
	PreOrder(root->RChild);
	VisitTNode(root->data);
}
