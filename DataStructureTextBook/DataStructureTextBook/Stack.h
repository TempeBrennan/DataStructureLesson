#pragma once
# define StackOriginalSize  8
#include "stdbool.h"

typedef struct Stack {
	int Count;
	int MaxCount;
	int EleSize;
	void * Start;
} Stack, *StackPTR;

StackPTR CreateStack(int size);

void Push(StackPTR stack, void* data);

void* Pop(StackPTR stack);

void* Top(StackPTR stack);

bool IsStackEmpty(StackPTR stack);