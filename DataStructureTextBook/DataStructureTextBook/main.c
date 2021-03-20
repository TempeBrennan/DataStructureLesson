#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"
#include "Tree.h"
#include "Map.h"


int main(void) {
	/*BiTree tree1 = CreateTNode('A');
	BiTree tree2 = CreateTNode('B');
	BiTree* result = NULL;
	StackPTR stack = CreateStack(sizeof(BiTNode));
	Push(stack, &tree1);
	Push(stack, &tree2);
	result = Top(stack);*/

	AdjMatrix* map1 = CreateMap1();
	// 测试使用递归的方法，深度遍历图
	//TraverseG1(map1);

	TraverseG2(map1);
	getch();
	return 0;
}