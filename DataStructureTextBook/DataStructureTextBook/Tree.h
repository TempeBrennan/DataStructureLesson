#pragma once
typedef struct Node {
	char Data;
	struct Node* LChild;
	struct Node* RChild;
} BiTNode, *BiTree;

typedef struct ClueNode {
	char Data;
	struct Node* LChild;
	struct Node* RChild;
	int LTag;
	int RTag;
} BiClueTNode, *BiClueTree;