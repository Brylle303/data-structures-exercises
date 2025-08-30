#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "HeapPrefi.h"
#include "addNodes.c"
#include "createNode.c"
#include "heapifyUpMax.c"

int main()
{
    char choice;
    do {
        system("cls");
        heapRoot = NULL;
        heapifyCount = 0;

        printf("=== HEAP TREE ADT ===\n\n");
        addNodes();

        printf("\nNumber of Heapify Actions: %d\n", heapifyCount);

        int internal = 0, external = 0;
        countNodes(heapRoot, &internal, &external);
        printf("Internal Nodes: %d\n", internal);
        printf("External Nodes: %d\n", external);

        breadthFirstTraversal();

        printf("\n\nAgain? [Y/N]: ");
        scanf(" %c", &choice);
        getchar(); // clear newline
    } while (choice == 'Y' || choice == 'y');

    printf("Successfully exited!\n");
    return 0;
}

void insertNode(int value) {
    HeapNode *insertedNode = NULL;

    if (!heapRoot) {
        heapRoot = createNode(value);
        return;
    }

    HeapNode* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = heapRoot;

    while (front < rear) {
        HeapNode* temp = queue[front++];

        if (!temp->left) {
            HeapNode* newNode = createNode(value);
            newNode->parent = temp;
            temp->left = newNode;
            insertedNode = newNode;
            break;
        } else {
            queue[rear++] = temp->left;
        }

        if (!temp->right) {
            HeapNode* newNode = createNode(value);
            newNode->parent = temp;
            temp->right = newNode;
            insertedNode = newNode;
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }

    heapifyUpMax(insertedNode);
}

void countNodes(HeapNode* node, int* internal, int* external) {
    if (!node) return;

    if (node->left || node->right)
        (*internal)++;
    else
        (*external)++;

    countNodes(node->left, internal, external);
    countNodes(node->right, internal, external);
}

void breadthFirstTraversal() {
    if (!heapRoot) return;

    HeapNode* queue[MAX_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = heapRoot;

    printf("Breadth First Traversal: ");
    while (front < rear) {
        HeapNode* current = queue[front++];
        printf("%d ", current->data);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
    printf("\n");
}
