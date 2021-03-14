#pragma once

#define MAXVEX 1000
#define INVALID 32767

typedef char Vextype;

typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;

typedef struct ArcNode {
	int adjvex;
	int weight;
	struct ArcNode* next;
}ArcNode;

typedef struct VertexNode {
	char vexdata;
	ArcNode *head;
}VertexNode;

typedef struct {
	VertexNode vertex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjList;

AdjMatrix * CreateMap1();
void testDFS1();
int TopSort(AdjList G);