#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void traverse_breadth_first(Node* vertex) {
    if (vertex == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = vertex;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->value);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}
