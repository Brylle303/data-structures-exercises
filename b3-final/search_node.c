#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int search_node(Node* vertex, int value) {
    if (vertex == NULL) {
        return 0;
    }
    if (value == vertex->value) {
        return 1;
    } else if (value < vertex->value) {
        return search_node(vertex->left, value);
    } else {
        return search_node(vertex->right, value);
    }
}

