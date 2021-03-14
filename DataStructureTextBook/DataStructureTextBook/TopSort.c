#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "stdbool.h"
#include "Stack.h"
#include "Queue.h"

void FindID(AdjList G, int indegree[MAXVEX]) {
	int i;
	ArcNode *p;
	for (int i = 0; i < G.vexnum; i++) {
		p = G.vertex[i].head;
		while (p != NULL) {
			indegree[p->adjvex]++;
			p = p->next;
		}
	}
}

int TopSort(AdjList G) {
	QueuePTR Q = CreateQueue();
	int indegree[MAXVEX];
	int i, count, k;
	ArcNode*p;
	FindID(G, indegree);

	for (int i = 0; i < G.vexnum; i++) {
		if (indegree[i] == 0) {
			EnterQueue(Q, i);
		}
	}
	count = 0;

	while (!EmptyQueue(Q))
	{
		i = DeleteQueue(Q);
		printf("Now visit %c\n", G.vertex[i].vexdata);
		count++;
		p = G.vertex[i].head;
		while (p != NULL)
		{
			k = p->adjvex;
			indegree[k]--;
			if (indegree[k] == 0) {
				EnterQueue(Q, k);
			}
			p = p->next;
		}
	}

	if (count < G.vexnum) {
		return 0;
	}
	else {
		return 1;
	}
}