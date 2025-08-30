#ifndef SORTER_H
#define SORTER_H


// STRUCT
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Linked list functions
Node* createNode(int data);
void insertEnd(Node **head, int data);
void printList(Node *head);
void freeList(Node *head);

// Sorting functions
void bubbleSort(Node **head, bool ascending);
void selectionSort(Node **head, bool ascending);
void insertionSort(Node **head, bool ascending);

#endif
