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