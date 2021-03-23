#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include "Map.h"

#define MAXVEX 99999

void Prim(AdjMatrix *G, int start) {
	struct
	{
		int adjvex;
		int lowcost;
	} closedge[MAXVEX];

	int i, e, k, m, min = MAXVEX;
	closedge[start].lowcost = 0;

	for (int i = 0; i < G->vexnum; i++) {
		if (i != start) {
			closedge[i].adjvex = start;
			closedge[i].lowcost = G->arcs[start][i];
		}
	}

	for (e = 0; e < G->vexnum - 1; e++) {
		min = MAXVEX;
		for (k = 0; k < G->vexnum; k++) {
			if (closedge[k].lowcost != 0 && closedge[k].lowcost < min) {
				m = k;
				min = closedge[k].lowcost;
			}
		}
		printf("Now we add %c --> %c\n", G->vex[m], G->vex[closedge[m].adjvex]);
		closedge[m].lowcost = 0;

		for (i = 0; i < G->vexnum; i++) {
			if (i != m && G->arcs[m][i] < closedge[i].lowcost) {
				closedge[i].lowcost = G->arcs[m][i];
				closedge[i].adjvex = m;
			}
		}
	}
}

AdjMatrix * CreateMapForPrim() {
	AdjMatrix *G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	G->vexnum = 10;
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
	G->vex[9] = 'J';

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			G->arcs[i][j] = INVALID;
		}
	}

	G->arcs[0][1] = 5;
	G->arcs[0][2] = 6;

	G->arcs[1][0] = 5;
	G->arcs[1][3] = 3;

	G->arcs[2][0] = 6;
	G->arcs[2][3] = 6;
	G->arcs[2][4] = 3;

	G->arcs[3][1] = 3;
	G->arcs[3][2] = 6;
	G->arcs[3][4] = 3;
	G->arcs[3][5] = 4;
	G->arcs[3][6] = 4;

	G->arcs[4][2] = 3;
	G->arcs[4][3] = 3;
	G->arcs[4][5] = 1;
	G->arcs[4][7] = 4;

	G->arcs[5][3] = 4;
	G->arcs[5][4] = 1;
	G->arcs[5][8] = 5;

	G->arcs[6][3] = 4;
	G->arcs[6][9] = 4;

	G->arcs[7][4] = 4;
	G->arcs[7][8] = 2;

	G->arcs[8][5] = 5;
	G->arcs[8][7] = 2;
	G->arcs[8][9] = 2;

	G->arcs[9][6] = 4;
	G->arcs[9][8] = 2;
	return G;
}