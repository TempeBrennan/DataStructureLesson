#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include "Stack.h"


StackPTR CreateStack(int eleSize) {
	StackPTR stack = (StackPTR)malloc(sizeof(Stack));
	stack->Count = 0;
	stack->MaxCount = StackOriginalSize;
	stack->EleSize = eleSize;
	stack->Start = (void*)malloc(eleSize*StackOriginalSize);
	return stack;
}

void Push(StackPTR stack, void* data) {
	if (stack->Count == stack->MaxCount)
	{
		stack->MaxCount += StackOriginalSize;
		realloc(stack->Start, stack->MaxCount);
	}

	// 可以先随便指定一个类型
	void* dest = (char*)stack->Start + (stack->Count)*(stack->EleSize);
	memcpy(dest, data, stack->EleSize);
	stack->Count++;
}

void* Pop(StackPTR stack) {
	void *data, *result = malloc(stack->EleSize);
	stack->Count--;
	data = (char*)stack->Start + (stack->Count)*(stack->EleSize);
	memcpy(result, data, stack->EleSize);
	return result;
}

void* Top(StackPTR stack) {
	void *data, *result = malloc(stack->EleSize);
	data = (char*)stack->Start + (stack->Count - 1)*(stack->EleSize);
	memcpy(result, data, stack->EleSize);
	return result;
}

bool IsStackEmpty(StackPTR stack) {
	return stack->Count == 0;
}