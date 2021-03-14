#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

AdjMatrix * CreateMap1() {
	AdjMatrix *G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	G->vexnum = 9;
	G->arcnum = 11;

	G->vex[0] = 'A';
	G->vex[1] = 'B';
	G->vex[2] = 'C';
	G->vex[3] = 'D';
	G->vex[4] = 'E';
	G->vex[5] = 'F';
	G->vex[6] = 'G';
	G->vex[7] = 'H';
	G->vex[8] = 'I';

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			G->arcs[i][j] = INVALID;
		}
	}

	G->arcs[0][1] = 1;
	G->arcs[0][2] = 1;
	G->arcs[0][3] = 1;

	G->arcs[1][0] = 1;
	G->arcs[1][3] = 1;
	G->arcs[1][4] = 1;

	G->arcs[2][0] = 1;
	G->arcs[2][5] = 1;

	G->arcs[3][0] = 1;
	G->arcs[3][1] = 1;
	G->arcs[3][5] = 1;
	G->arcs[3][6] = 1;

	G->arcs[4][1] = 1;
	G->arcs[4][6] = 1;

	G->arcs[5][2] = 1;
	G->arcs[5][3] = 1;
	G->arcs[5][6] = 1;

	G->arcs[6][3] = 1;
	G->arcs[6][4] = 1;
	G->arcs[6][5] = 1;

	G->arcs[7][8] = 1;

	G->arcs[8][7] = 1;
	return G;
}

// P182 ͼ7.30
AdjList * CreateMap2() {
	AdjList* G = (AdjList*)malloc(sizeof(AdjList));
	G->vexnum = 8;
	G->arcnum = 10;

	//A
	G->vertex[0].vexdata = 'A';
	ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = 2;
	G->vertex[0].head = p;

	ArcNode* next = (ArcNode*)malloc(sizeof(ArcNode));
	next->adjvex = 6;
	p->next = next;

	//B
	G->vertex[1].vexdata = 'B';
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = 6;
	G->vertex[1].head = p;

	next = (ArcNode*)malloc(sizeof(ArcNode));
	next->adjvex = 7;
	p->next = next;

	//C
	G->vertex[2].vexdata = 'C';
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = 3;
	G->vertex[2].head = p;

	//D
	G->vertex[3].vexdata = 'D';
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = 4;
	G->vertex[3].head = p;

	//E
	G->vertex[4].vexdata = 'E';

	//F
	G->vertex[5].vexdata = 'F';
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = 4;
	G->vertex[5].head = p;

	//G
	G->vertex[6].vexdata = 'G';
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = 3;
	G->vertex[6].head = p;

	next = (ArcNode*)malloc(sizeof(ArcNode));
	next->adjvex = 5;
	p->next = next;

	//H
	G->vertex[7].vexdata = 'H';
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = 5;
	G->vertex[7].head = p;
}