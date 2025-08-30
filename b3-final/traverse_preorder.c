#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void traverse_preorder(Node* vertex) {
    if (vertex != NULL) {
        printf("%d ", vertex->value);
        traverse_preorder(vertex->left);
        traverse_preorder(vertex->right);
    }
}
