#ifndef GENTREE_H_INCLUDED
#define GENTREE_H_INCLUDED

#define MAX_VALUES 100
#define MAX_INPUT 100

//STRUCTURE

typedef struct Node
{
    int data;
    int childCnt;

    struct Node **children;
} Node;


//FUNCTION PROTOTYPE

Node* createNode(int value, int order);
Node* buildTree(int values[], int n, int order);
void freeTree(Node *root);
void printInternalExternal(Node *root);
void printParent(Node *root);
void printChild(Node *root);
void printSiblings(Node *root);



#endif // GENTREE_H_INCLUDED
