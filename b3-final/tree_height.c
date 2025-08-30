#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int tree_height(Node* vertex) {
    if (vertex == NULL) {
        return 0;
    }
    int left_height = tree_height(vertex->left);
    int right_height = tree_height(vertex->right);
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}
