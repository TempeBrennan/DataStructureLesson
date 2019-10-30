#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "Tree.h"
#include "Stack.h"

HuffmanNode Select(HuffmanNodeTree ht, int lastCount, int first, int second) {
	first = 1;
	for (int i = 2; i <= lastCount; i++) {
		if (ht[i].Data == -1 || ht[i].Parent == 0) {
			continue;
		}

		if (ht[i].Data < ht[first].Data) {
			first = i;
		}
	}

	second = first == 1 ? 2 : 1;
	for (int i = 1; i <= lastCount; i++) {
		if (ht[i].Data == -1 || ht[i].Parent == 0) {
			continue;
		}
		if (i == first) {
			continue;
		}

		if (ht[i].Data <= ht[second].Data) {
			second = i;
		}
	}
}

void CreateHuffmanTree(HuffmanNodeTree ht, int data[], int leafCount) {
	int total = leafCount * 2 - 1;
	for (int i = 1; i <= leafCount; i++) {
		ht[i].Data = data[i];
		ht[i].LChild = 0;
		ht[i].RChild = 0;
		ht[i].Parent = 0;
	}

	for (int i = leafCount + 1; i <= total; i++) {
		ht[i].Data = -1;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
		ht[i].Parent = 0;
	}

	for (int i = leafCount + 1; i < total; i++) {
		int first, second;
		Select(ht, i, &first, &second);
		ht[first].Parent = i;
		ht[second].Parent = i;
		ht[i].Data = ht[first].Data + ht[second].Data;
		ht[i].LChild = first;
		ht[i].RChild = second;
	}
}

