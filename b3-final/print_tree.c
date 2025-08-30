#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void print_tree(Node* vertex, int level, int space) {
    if (vertex == NULL) return;

    // Print right child first
    print_tree(vertex->right, level + 1, space);

    // Print current node
    print_spaces(level * space);
    printf("%d\n", vertex->value);

    // Print left child
    print_tree(vertex->left, level + 1, space);
}
