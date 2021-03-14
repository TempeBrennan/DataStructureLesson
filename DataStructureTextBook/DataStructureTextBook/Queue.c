#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include "Queue.h"

QueuePTR CreateQueue() {
	QueuePTR queue = (QueuePTR)malloc(sizeof(Queue));
	queue->front = queue->rear = MAXQUEUESIZE - 1;
	return queue;
}

bool EnterQueue(QueuePTR q, int x) {
	if ((q->rear + 1) % MAXQUEUESIZE == q->front) {
		printf("队列已满");
		return false;
	}
	else {
		q->rear = (q->rear + 1) % MAXQUEUESIZE;
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
		q->front = (q->front + 1) % MAXQUEUESIZE;
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