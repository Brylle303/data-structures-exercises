#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void display_tree(Node* vertex) {
    if (vertex == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    int height = tree_height(vertex);
    int space = 4; // Adjust space for alignment
    print_tree(vertex, 0, space);
}
