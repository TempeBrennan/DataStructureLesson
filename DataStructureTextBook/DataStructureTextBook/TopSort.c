#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "stdbool.h"
#include "Stack.h"

void findID(AdjList G, int indegree[MAXVEX]) {
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++) {
		indegree[i] = 0;
	}
	for (int i = 0; i < G.vexnum; i++) {
		p = G.vertex[i].head;
		while (p != NULL) {
			indegree[p->adjvex]++;
			p = p->next;
		}
	}
}

int topSort(AdjList G) {
	QueuePTR Q = CreateQueue();
	int indegree[MAXVEX];
	int i, count, k;
	ArcNode*p;
	findID(G, indegree);

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

AdjList* createTopSort() {
	AdjList* adjList = (AdjList*)malloc(sizeof(AdjList));
	adjList->arcnum = 10;
	adjList->vexnum = 8;

	adjList->vertex[0].vexdata = 'A';
	adjList->vertex[0].head = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[0].head->adjvex = 2;
	adjList->vertex[0].head->next = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[0].head->next->adjvex = 6;
	adjList->vertex[0].head->next->next = NULL;

	adjList->vertex[1].vexdata = 'B';
	adjList->vertex[1].head = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[1].head->adjvex = 6;
	adjList->vertex[1].head->next = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[1].head->next->adjvex = 7;
	adjList->vertex[1].head->next->next = NULL;

	adjList->vertex[2].vexdata = 'C';
	adjList->vertex[2].head = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[2].head->adjvex = 3;
	adjList->vertex[2].head->next = NULL;

	adjList->vertex[6].vexdata = 'G';
	adjList->vertex[6].head = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[6].head->adjvex = 3;
	adjList->vertex[6].head->next = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[6].head->next->adjvex = 5;
	adjList->vertex[6].head->next->next = NULL;

	adjList->vertex[7].vexdata = 'H';
	adjList->vertex[7].head = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[7].head->adjvex = 5;
	adjList->vertex[7].head->next = NULL;

	adjList->vertex[3].vexdata = 'D';
	adjList->vertex[3].head = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[3].head->adjvex = 4;
	adjList->vertex[3].head->next = NULL;

	adjList->vertex[5].vexdata = 'F';
	adjList->vertex[5].head = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[5].head->adjvex = 4;
	adjList->vertex[5].head->next = NULL;

	adjList->vertex[4].vexdata = 'E';
	adjList->vertex[4].head = (ArcNode*)malloc(sizeof(ArcNode));
	adjList->vertex[4].head = NULL;

	return adjList;
}