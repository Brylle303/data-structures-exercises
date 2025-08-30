#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void traverse_inorder(Node* vertex) {
    if (vertex != NULL) {
        traverse_inorder(vertex->left);
        printf("%d ", vertex->value);
        traverse_inorder(vertex->right);
    }
}
