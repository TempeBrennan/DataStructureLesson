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
		return result;
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

QueuePTR CreateQueue() {
	QueuePTR queue = (QueuePTR)malloc(sizeof(Queue));
	queue->front = queue->rear = MAXSTACKSIZE - 1;
	return queue;
}

bool EnterQueue(QueuePTR q, int x) {
	if ((q->rear + 1) % MAXSTACKSIZE == q->front) {
		printf("队列已满");
		return false;
	}
	else {
		q->rear = (q->rear + 1) % MAXSTACKSIZE;
		q->data[q->rear] = x;
		return true;
	}
}

int DeleteQueue(QueuePTR q) {
	if (q->front == q->rear) {
		printf("队列为空");
		return -1;
	}
	else {
		q->front = (q->front + 1) % MAXSTACKSIZE;
		return q->data[q->front];
	}
}

bool EmptyQueue(QueuePTR q) {
	if (q->front == q->rear) {
		return true;
	}
	else {
		return false;
	}
}