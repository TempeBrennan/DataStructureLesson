#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"
#include "Tree.h"

int main(void) {
	BiTree tree1 = CreateTNode('A');
	BiTree tree2 = CreateTNode('B');
	BiTree* result = NULL;
	StackPTR stack = CreateStack(sizeof(BiTNode));
	Push(stack, &tree1);
	Push(stack, &tree2);
	result = Top(stack);
	return 0;
}