#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "stdbool.h"
#include "Stack.h"

int visited1[MAXVEX] = { 0 };

void dfs1(AdjMatrix *G, int vexIndex);
bool isVisited1(int index);
void visit1(AdjMatrix *G, int index);
void TraverseG1(AdjMatrix *G);

void visit1(AdjMatrix *G, int index) {
	printf("Now we visited %c\n", G->vex[index]);
}

bool isVisited1(int index) {
	return visited1[index] == 1;
}

void testDFS1() {
	TraverseG1(CreateMap1());
}

int FirstAdjVex(AdjMatrix *G, int vexIndex) {
	for (int i = 0; i < G->vexnum; i++) {
		if (G->arcs[vexIndex][i] == 1) {
			return i;
		}
	}
	return -1;
}

int NextAdjVex(AdjMatrix *G, int vexIndex, int current) {
	for (int i = current + 1; i < G->vexnum; i++) {
		if (G->arcs[vexIndex][i] == 1) {
			return i;
		}
	}
	return -1;
}

void dfs1(AdjMatrix *G, int v0) {
	visit1(G, v0);
	visited1[v0] = 1;
	int w = FirstAdjVex(G, v0);
	while (w != -1) {
		if (!isVisited1(w)) {
			dfs1(G, w);
		}
		w = NextAdjVex(G, v0, w);
	}
}

// 7.4 图的遍历 7.4.1
// P174 算法7.3，深度优先搜索遍历图g
void TraverseG1(AdjMatrix *G) {
	for (int i = 0; i < MAXVEX; i++) {
		visited1[i] = 0;
	}
	for (int i = 0; i < G->vexnum; i++) {
		if (!isVisited1(i)) {
			dfs1(G, i);
		}
	}
}

void dfs2(AdjMatrix *G, int v0) {
	StackPTR S = CreateStack();
	Push_SeqStack(S, v0);
	int w;
	while (!Empty_SeqStack(S))
	{
		int v = Pop_SeqStack(S);
		if (visited1[v] != 1) {
			visit1(G, v);
			visited1[v] = 1;
		}
		w = FirstAdjVex(G, v);
		while (w != -1)
		{
			if (visited1[w] != 1) {
				Push_SeqStack(S, w);
			}
			w = NextAdjVex(G, v, w);
		}
	}
}

// 7.4 图的遍历 7.4.1
// P174 算法7.4，非递归，深度优先搜索遍历图g
void TraverseG2(AdjMatrix *G) {
	for (int i = 0; i < MAXVEX; i++) {
		visited1[i] = 0;
	}
	for (int i = 0; i < G->vexnum; i++) {
		if (!isVisited1(i)) {
			dfs2(G, i);
		}
	}
}

void bfs1(AdjMatrix*G, int v0) {
	visit1(G, v0);
	visited1[v0] = 1;
	QueuePTR Q = CreateQueue();
	while (!EmptyQueue(Q))
	{
		int v = DeleteQueue(Q);
		int w = FirstAdjVex(G, v);
		while (w != -1)
		{
			if (!isVisited1(w)) {
				visit1(G, w);
				visited1[w] = 1;
				EnterQueue(Q, w);
			}
		}
		w = NextAdjVex(G, v, w);
	}
}

// 7.4 图的遍历 7.4.2
// P176 算法7.6，广度优先搜索遍历图g
void TraverseG3(AdjMatrix *G) {
	for (int i = 0; i < MAXVEX; i++) {
		visited1[i] = 0;
	}
	for (int i = 0; i < G->vexnum; i++) {
		bfs1(G, i);
	}
}