#pragma once
# define StackOriginalSize  8
#include "stdbool.h"

#define MAXSTACKSIZE 100000
typedef struct {
	int data[MAXSTACKSIZE];
	int top;
}Stack, *StackPTR;

StackPTR CreateStack();

bool Empty_SeqStack(StackPTR stack);

int Push_SeqStack(StackPTR stack, int x);

int Pop_SeqStack(StackPTR stack);

int Top_SeqStack(StackPTR stack);