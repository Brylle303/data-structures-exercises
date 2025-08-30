#ifndef SPLAYTREE_H_INCLUDED
#define SPLAYTREE_H_INCLUDED

//STRUCT

typedef struct Node
{
    int data;

    struct Node* leftNode;
    struct Node* rightNode;
    struct Node* parentNode;

}Node;

//FUNCTION PROTOTYPES

Node *createNode(int key);
Node *bstInsert(Node **root, Node *parentNode, int key);
Node *findLargest(Node *root);
Node *searchNode(Node **root, int key);

void addNode(Node **root, int key);

void displayTree(Node *root);
void printNode(Node *node, COORD pos, int offset);
void drawConnections(Node *node, int x, int y, int offset);
void animateTree(Node **root, Node *splayNode);

void rotateLeft(Node *x);
void rotateRight(Node *x);

void deleteFunc(Node **root, int key);
void deleteNode(Node **root, int key);



#endif // SPLAYTREE_H_INCLUDED
