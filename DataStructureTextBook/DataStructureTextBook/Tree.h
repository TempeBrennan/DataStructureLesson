#pragma once
typedef struct Node {
	char data;
	struct Node* LChild;
	struct Node* RChild;
} BiTNode, *BiTree;