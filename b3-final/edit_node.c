#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node* edit_node(Node* vertex, int old_value, int new_value, int* success) {
    *success = 0;
    if (search_node(vertex, old_value)) {
        vertex = delete_node(vertex, old_value, success);
        if (*success) {
            vertex = add_node(vertex, new_value);
        }
    }
    return vertex;
}
