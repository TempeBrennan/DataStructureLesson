#pragma once

#define MAXVEX 1000
#define INVALID 32767
#define MAXVALUE 99999999

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

//typedef struct
//{
//	int adjvex;
//	int lowcost;
//}Closedge;

AdjMatrix * CreateMap1();
void testDFS1();
int topSort(AdjList G);
void TraverseG1(AdjMatrix *G);
void TraverseG2(AdjMatrix *G);
void TraverseG3(AdjMatrix *G);
AdjMatrix * CreateMapForPrim();
void Prim(AdjMatrix *G, int start);
int topSort(AdjList G);
AdjList* createTopSort();