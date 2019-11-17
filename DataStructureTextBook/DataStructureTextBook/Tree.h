#pragma once
#define N 30
#define M 2*N-1
typedef struct Node {
	char Data;
	struct Node* LChild;
	struct Node* RChild;
} BiTNode, *BiTree;

typedef struct ClueNode {
	char Data;
	struct ClueNode* LChild;
	struct ClueNode* RChild;
	int LTag;
	int RTag;
} BiClueTNode, *BiClueTree;

typedef struct HuffmanNode {
	int Data;
	int LChild;
	int RChild;
	int Parent;
	int RTag;
} HuffmanNode, HuffmanNodeTree[M + 1];