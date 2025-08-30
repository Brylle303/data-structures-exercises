#ifndef HEAPPREFI_H_INCLUDED
#define HEAPPREFI_H_INCLUDED

#define MAX_SIZE 100

typedef struct HeapNode {
    int data;
    struct HeapNode *left, *right, *parent;
} HeapNode;

HeapNode *heapRoot = NULL;
int heapifyCount = 0;

// Function declarations
void addNodes();
void insertNode(int value);
HeapNode* createNode(int value);
void heapifyUpMax(HeapNode* node);
void countNodes(HeapNode* node, int* internal, int* external);
void breadthFirstTraversal();

#endif // HEAPPREFI_H_INCLUDED
