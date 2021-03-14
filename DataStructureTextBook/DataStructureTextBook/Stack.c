#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include "Stack.h"


StackPTR CreateStack() {
	StackPTR stack = (StackPTR)malloc(sizeof(Stack));
	stack->top = -1;
	return stack;
}

bool Empty_SeqStack(StackPTR stack) {
	if (stack->top == -1) {
		return true;
	}
	else {
		return false;
	}
}

int Push_SeqStack(StackPTR stack, int x) {
	if (stack->top == MAXSTACKSIZE - 1) {
		return -1;
	}
	else {
		stack->top++;
		stack->data[stack->top] = x;
		return 1;
	}
}

int Pop_SeqStack(StackPTR stack) {
	if (Empty_SeqStack(stack)) {
		return -1;
	}
	else
	{
		int result = stack->data[stack->top];
		stack->top--;
		return 1;
	}
}

int Top_SeqStack(StackPTR stack) {
	if (Empty_SeqStack(stack)) {
		return -1;
	}
	else
	{
		return stack->data[stack->top];
	}
}