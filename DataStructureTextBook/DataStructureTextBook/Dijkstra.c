#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "stdbool.h"
#include "Stack.h"

void Dijkstra(AdjMatrix *G, int start, int end, int dist[], int path[][MAXVEX]) {
	int mindist, i, j, k, t = 1;
	for (i = 1; i <= G->vexnum; i++) {
		dist[i] = G->arcs[start][i];
		if (G->arcs[start][i] != MAXVALUE) {
			path[i][1] = start;
		}
	}
	path[start][0] = 1;
	for (i = 2; i <= G->vexnum; i++) {
		mindist = MAXVALUE;
		for (j = 1; j <= G->vexnum; j++) {
			if (!path[j][0] && dist[j] < mindist) {
				k = j;
				mindist = dist[j];
			}
		}

		if (mindist == MAXVALUE) {
			return;
		}

		path[k][0] = 1;
		for (j = 1; j <= G->vexnum; j++) {
			if (!path[j][0] && G->arcs[k][j] < MAXVALUE && dist[k] + G->arcs[k][j] < dist[j]) {
				dist[j] = dist[k] + G->arcs[k][j];
				t = 1;
				while (path[k][t] != 0)
				{
					path[j][t] = path[k][t];
					t++;
				}
				path[j][t] = k;
				path[j][t + 1] = 0;
			}
		}
	}
}

void Floyd(AdjMatrix *G, int F[][MAXVEX]) {
	int path[MAXVEX][MAXVEX];
	int i, j, k;
	for (i = 0; i < G->vexnum; i++) {
		for (j = 0; j < G->vexnum; j++) {
			F[i][j] = G->arcs[i][j];
			path[i][j] = MAXVALUE;
		}
	}

	for (i = 0; i < G->vexnum; i++) {
		for (j = 0; j < G->vexnum; j++) {
			for (k = 0; k < G->vexnum; k++) {
				if (F[i][j] > F[i][k] + F[k][j]) {
					F[i][j] = F[i][k] + F[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}