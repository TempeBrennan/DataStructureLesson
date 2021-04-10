#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "stdbool.h"
#include "Stack.h"

void Dijkstra(AdjMatrix *G, int start) {
	int mindist, i, j, k, t = 1;
	int dist[10];
	int path[100][MAXVEX];
	int isUsed[10];

	for (i = 0; i < G->vexnum; i++) {
		dist[i] = G->arcs[start][i];
		if (G->arcs[start][i] != MAXVALUE) {
			path[i][0] = start;
			path[i][1] = i;
			path[i][2] = -1;
		}
	}
	isUsed[start] = 1;
	for (i = 1; i < G->vexnum; i++) {
		mindist = MAXVALUE;
		for (j = 0; j < G->vexnum; j++) {
			if (isUsed[j] != 1 && dist[j] < mindist) {
				k = j;
				mindist = dist[j];
			}
		}

		if (mindist == MAXVALUE) {
			return;
		}

		// Now find the shortest path
		// Print
		isUsed[k] = 1;
		printf("now we found %c-->%c nearest distance, path is ", G->vex[start], G->vex[k]);
		for (int t = 0; t < 100; t++) {
			if (path[k][t] == -1) {
				break;
			}
			else if (t != 0) {
				printf("-->");
			}
			printf("%c", G->vex[path[k][t]]);
		}
		printf("\n");
		// Print end

		for (j = 0; j < G->vexnum; j++) {
			if (isUsed[j] != 1 && G->arcs[k][j] < MAXVALUE && dist[k] + G->arcs[k][j] < dist[j]) {
				dist[j] = dist[k] + G->arcs[k][j];
				t = 0;
				while (path[k][t] != -1)
				{
					path[j][t] = path[k][t];
					t++;
				}
				path[j][t] = j;
				path[j][t + 1] = -1;
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

AdjMatrix * CreateMapForDijkstra() {
	AdjMatrix *G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	G->vexnum = 7;
	G->arcnum = 12;

	G->vex[0] = 'A';
	G->vex[1] = 'B';
	G->vex[2] = 'C';
	G->vex[3] = 'D';
	G->vex[4] = 'E';
	G->vex[5] = 'F';
	G->vex[6] = 'G';

	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j] = INVALID;
		}
	}

	G->arcs[0][1] = 2;
	G->arcs[0][2] = 3;
	G->arcs[0][3] = 2;

	G->arcs[1][2] = 2;
	G->arcs[1][5] = 8;

	G->arcs[2][3] = 1;
	G->arcs[2][4] = 3;
	G->arcs[2][5] = 5;

	G->arcs[3][4] = 5;

	G->arcs[4][5] = 3;
	G->arcs[4][6] = 9;

	G->arcs[5][6] = 5;
	return G;
}