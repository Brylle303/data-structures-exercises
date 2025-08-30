#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void traverse_postorder(Node* vertex) {
    if (vertex != NULL) {
        traverse_postorder(vertex->left);
        traverse_postorder(vertex->right);
        printf("%d ", vertex->value);
    }
}
