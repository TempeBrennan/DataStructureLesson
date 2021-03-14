#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include "Map.h"

#define MAXVEX 1000000

void Prim(AdjMatrix *G, int start) {
	struct
	{
		int adjvex;
		int lowcost;
	} closedge[MAXVEX];

	int i, e, k, m, min=MAXVEX;
	closedge[start].lowcost = 0;

	for (int i = 0; i < G->vexnum; i++) {
		if (i != start) {
			closedge[i].adjvex = start;
			closedge[i].lowcost = G->arcs[start][i];
		}
	}

	for (k = 0; k < G->vexnum; k++) {
		if (closedge[k].lowcost != 0 && closedge[k].lowcost < min) {
			m = k;
			min = closedge[k].lowcost;
		}
	}
	closedge[m].lowcost = 0;

	for (i = 0; i < G->vexnum; i++) {
		if (i != m && G->arcs[m][i] < closedge[i].lowcost) {
			closedge[i].lowcost = G->arcs[m][i];
			closedge[i].adjvex = m;
		}
	}
}