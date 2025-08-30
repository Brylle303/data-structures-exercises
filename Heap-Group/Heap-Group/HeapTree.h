#ifndef HEAPTREE_H_INCLUDED
#define HEAPTREE_H_INCLUDED

#define MAX_SIZE 100

//STRUCT
typedef struct HeapNode
{
    int value;
    struct HeapNode *left, *right, *parent;

} HeapNode;

HeapNode *minRoot = NULL, *maxRoot = NULL;
int nodeCount = 0;

//FUNCTION PROTOTYPES
void gotoxy(int x, int y);
HeapNode* createNode(int value, HeapNode* parent);
HeapNode* insertLevelOrder(HeapNode* root, int value, HeapNode** inserted);
void printHeapTree(HeapNode* node, int x, int y, int offset);
void printHeaps();
void heapifyUpMin(HeapNode* node);
void heapifyUpMax(HeapNode* node);
void insert(int value);
void heapifyDownMin(HeapNode* node);
void heapifyDownMax(HeapNode* node);
void getLastNode(HeapNode* root, int index, int target, HeapNode** last);
void deleteRoot();
void addNodes();


#endif // HEAPTREE_H_INCLUDED
