#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node* add_node(Node* vertex, int value) {
    if (vertex == NULL) {
        vertex = create_node(value);
        most_recent_node = vertex; // Track the most recently added node
        return vertex;
    }

    // Use a queue to perform breadth-first insertion
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = vertex;

    while (front < rear) {
        Node* current = queue[front++];

        if (current->left == NULL) {
            current->left = create_node(value);
            most_recent_node = current->left; // Track the most recently added node
            break;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = create_node(value);
            most_recent_node = current->right; // Track the most recently added node
            break;
        } else {
            queue[rear++] = current->right;
        }
    }

    return vertex;
}
