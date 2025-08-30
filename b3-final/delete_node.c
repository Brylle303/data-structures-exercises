#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node* delete_node(Node* vertex, int value, int* success) {
    if (vertex == NULL) {
        *success = 0;
        return NULL;
    }

    // Find the node to delete
    if (value < vertex->value) {
        vertex->left = delete_node(vertex->left, value, success);
    } else if (value > vertex->value) {
        vertex->right = delete_node(vertex->right, value, success);
    } else {
        // Node to delete found
        if (most_recent_node == NULL) {
            *success = 0;
            return vertex; // No nodes to replace with
        }

        // Replace the deleted node's value with the most recently added node's value
        vertex->value = most_recent_node->value;

        // Remove the most recently added node from its original position
        Node* parent = NULL;
        Node* current = vertex;
        while (current != most_recent_node) {
            parent = current;
            if (most_recent_node->value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (parent->left == most_recent_node) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }

        free(most_recent_node);
        most_recent_node = NULL; // Reset the most recently added node
        *success = 1;
    }

    return vertex;
}
