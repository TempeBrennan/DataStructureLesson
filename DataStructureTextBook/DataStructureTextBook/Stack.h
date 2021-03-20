#pragma once
# define StackOriginalSize  8
#include "stdbool.h"

#define MAXSTACKSIZE 100000
typedef struct {
	int data[MAXSTACKSIZE];
	int top;
}Stack, *StackPTR;

typedef struct {
	int data[MAXSTACKSIZE];
	int front, rear;
}Queue, *QueuePTR;

StackPTR CreateStack();

bool Empty_SeqStack(StackPTR stack);

int Push_SeqStack(StackPTR stack, int x);

int Pop_SeqStack(StackPTR stack);

int Top_SeqStack(StackPTR stack);

QueuePTR CreateQueue();

bool EnterQueue(QueuePTR q, int x);

int DeleteQueue(QueuePTR q);

bool EmptyQueue(QueuePTR q);